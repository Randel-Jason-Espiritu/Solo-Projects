import React, { useContext, useState, useEffect } from "react";
import Cam from "../img/cam.png";
import Add from "../img/add.png";
import More from "../img/more.png";
import Messages from "./Messages";
import Input from "./Input";
import { ChatContext } from "../context/ChatContext";
import Navbar from "./Navbar";
import Search from "./Search";
import Chats from "./Chats";
import Hamburger from "hamburger-react";

const Chat = () => {
  const { data } = useContext(ChatContext);
  const [showNavbar, setShowNavbar] = useState(false);
  const [isMobileView, setIsMobileView] = useState(false);

  const toggleNavbar = () => {
    setShowNavbar(!showNavbar);
  };

  useEffect(() => {
    const handleResize = () => {
      setIsMobileView(window.innerWidth <= 1024); // Adjust the breakpoint as per your requirements
    };

    window.addEventListener("resize", handleResize);
    handleResize();

    return () => {
      window.removeEventListener("resize", handleResize);
    };
  }, []);

  return (
    <div className="chat">
      <div className="chatInfo">
        {isMobileView && (
          <Hamburger
            direction="left"
            size={18}
            color="white"
            duration={0.1}
            toggled={showNavbar}
            toggle={toggleNavbar}
            className="hamburgerButton"
          />
        )}
        <span>{data.user?.displayName}</span>
        <div className="chatIcons">
          <img src={Cam} alt="" />
          <img src={Add} alt="" />
          <img src={More} alt="" />
        </div>
      </div>
      {showNavbar && (
        <div className="floatingNavbar">
          <Navbar />
          <Search />
          <Chats />
        </div>
      )}
      <Messages />
      <Input />
    </div>
  );
};

export default Chat;
