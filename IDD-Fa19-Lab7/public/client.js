/*
client.js

Author: Nikolas Martelaro (nmartelaro@gmail.com)
Extended: David Goeicke (da.goedicke@gmail.com)
Purpose: This run the interactivity and communication for the web app. This file
is served to the users web browser and executes on the browser.

Usage: This file is called automatically when the webpage is served.

//--Addition. Added a button handling for the `Take a picture` button.
*/

// WebSocket connection setup
var socket = io();

// send out LedOn message over socket
function ledON() {
  socket.emit('ledON');
}

// send out ledOFF message over socket
function ledOFF() {
  socket.emit('ledOFF');
}


//-- Addition: This function receives the new image name and applies it to html element.

socket.on('newPicture', function(msg) {
  document.getElementById('pictureContainer').src=msg;
});

socket.on('candy', function(msg){
  document.getElementById('candyContainer').src=msg;
});

// read the data from the message that the server sent and change the
// background of the webpage based on the data in the message
socket.on('server-msg', function(msg) {
  msg = msg.toString();
  console.log('msg:', msg);
  switch (msg) {
    case "light":
      document.body.style.backgroundColor = "black";
      console.log("black")
      break;
    case "dark":
      document.body.style.backgroundColor = "#a86832";
      console.log("orange");
      break;
    default:
      //console.log("something else");
      break;
  }
});
