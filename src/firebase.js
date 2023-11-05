import { initializeApp } from "firebase/app";
import { getAuth } from "firebase/auth";
import { getStorage } from "firebase/storage";
import { getFirestore } from "firebase/firestore";

const firebaseConfig = {
  apiKey: "AIzaSyCogadJR8lVBdC_aIoJv6cqnsSBZjsN82I",
  authDomain: "chat-714be.firebaseapp.com",
  projectId: "chat-714be",
  storageBucket: "chat-714be.appspot.com",
  messagingSenderId: "21769897099",
  appId: "1:21769897099:web:0410fe89db5b0dbea7408e"
};

// Initialize Firebase
export const app = initializeApp(firebaseConfig);
export const auth = getAuth();
export const storage = getStorage();
export const db = getFirestore()
