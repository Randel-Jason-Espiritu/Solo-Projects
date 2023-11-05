import React, { useState } from "react";
import Add from "../img/addAvatar.png";
import { createUserWithEmailAndPassword, updateProfile } from "firebase/auth";
import { auth, db, storage } from "../firebase";
import { ref, uploadBytesResumable, getDownloadURL } from "firebase/storage";
import { doc, setDoc, collection, getDocs } from "firebase/firestore";
import { useNavigate, Link } from "react-router-dom";

const Register = () => {
  const [displayNameError, setDisplayNameError] = useState("");
  const [emailError, setEmailError] = useState("");
  const [passwordError, setPasswordError] = useState("");
  const [loading, setLoading] = useState(false);
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    setLoading(true);
    e.preventDefault();
    const displayName = e.target[0].value;
    const email = e.target[1].value;
    const password = e.target[2].value;
    const file = e.target[3].files[0];

    try {
      // Check if display name already exists
      const displayNameExists = await checkIfDisplayNameExists(displayName);
      if (displayNameExists) {
        setDisplayNameError("Display name already taken");
        setEmailError("");
        setPasswordError("");
        setLoading(false);
        return;
      }

      // Check if email already exists
      const emailExists = await checkIfEmailExists(email);
      if (emailExists) {
        setEmailError("Email already registered");
        setDisplayNameError("");
        setPasswordError("");
        setLoading(false);
        return;
      }

      // Validate password
      const isValidPassword = validatePassword(password);
      if (!isValidPassword) {
        setPasswordError(
          "Password must contain at least one capital letter, number, special character"
        );
        setDisplayNameError("");
        setEmailError("");
        setLoading(false);
        return;
      }

      // Create user
      const res = await createUserWithEmailAndPassword(auth, email, password);

      // Create a unique image name
      const date = new Date().getTime();
      const storageRef = ref(storage, `${displayName + date}`);

      await uploadBytesResumable(storageRef, file).then(() => {
        getDownloadURL(storageRef).then(async (downloadURL) => {
          try {
            // Update profile
            await updateProfile(res.user, {
              displayName,
              photoURL: downloadURL,
            });
            // Create user on firestore
            await setDoc(doc(db, "users", res.user.uid), {
              uid: res.user.uid,
              displayName,
              email,
              photoURL: downloadURL,
            });

            // Create empty user chats on firestore
            await setDoc(doc(db, "userChats", res.user.uid), {});
            setDisplayNameError("");
            setEmailError("");
            setPasswordError("");
            navigate("/");
          } catch (err) {
            console.log(err);
            setDisplayNameError("");
            setEmailError("");
            setPasswordError("");
            setLoading(false);
          }
        });
      });
    } catch (err) {
      console.log(err);
      setDisplayNameError("");
      setEmailError("");
      setPasswordError("");
      setLoading(false);
    }
  };

  const checkIfDisplayNameExists = async (displayName) => {
    try {
      const usersSnapshot = await getDocs(collection(db, "users"));
      const users = usersSnapshot.docs.map((doc) => doc.data());
      return users.some((user) => user.displayName === displayName);
    } catch (err) {
      console.log(err);
      return false;
    }
  };

  const checkIfEmailExists = async (email) => {
    try {
      const usersSnapshot = await getDocs(collection(db, "users"));
      const users = usersSnapshot.docs.map((doc) => doc.data());
      return users.some((user) => user.email === email);
    } catch (err) {
      console.log(err);
      return false;
    }
  };

  const validatePassword = (password) => {
    const passwordRegex = /^(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;
    return passwordRegex.test(password);
  };

  return (
    <div className="formContainer">
      <div className="formWrapper">
        <span className="logo">BloodLine Chat</span>
        <span className="title">Register</span>
        <form onSubmit={handleSubmit}>
          <div className="inputContainer">
            <input required type="text" placeholder="Display name" />
            {displayNameError && (
              <span className="bubbleError">{displayNameError}</span>
            )}
          </div>
          <div className="inputContainer">
            <input required type="email" placeholder="Email" />
            {emailError && (
              <span className="bubbleError">{emailError}</span>
            )}
          </div>
          <div className="inputContainer">
            <input required type="password" placeholder="Password" />
            {passwordError && (
              <span className="bubbleError">{passwordError}</span>
            )}
          </div>
          <input required style={{ display: "none" }} type="file" id="file" />
          <label htmlFor="file">
            <img src={Add} alt="" />
            <span>Add an avatar</span>
          </label>
          <button disabled={loading}>Sign up</button>
          {loading && "Uploading please wait..."}
        </form>
        <p>
          Already have an account? <Link to="/Login">Login</Link>
        </p>
      </div>
    </div>
  );
};

export default Register;
