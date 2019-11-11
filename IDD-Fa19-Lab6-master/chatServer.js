/*
chatServer.js
Author: David Goedicke (da.goedicke@gmail.com)
Closley based on work from Nikolas Martelaro (nmartelaro@gmail.com) as well as Captain Anonymous (https://codepen.io/anon/pen/PEVYXz) who forked of an original work by Ian Tairea (https://codepen.io/mrtairea/pen/yJapwv)
*/

var express = require('express'); // web server application
var app = express(); // webapp
var http = require('http').Server(app); // connects http library to server
var io = require('socket.io')(http); // connect websocket library to server
var serverPort = 8000;


//---------------------- WEBAPP SERVER SETUP ---------------------------------//
// use express to create the simple webapp
app.use(express.static('public')); // find pages in public directory

// start the server and say what port it is on
http.listen(serverPort, function() {
  console.log('listening on *:%s', serverPort);
});
//----------------------------------------------------------------------------//


//---------------------- WEBSOCKET COMMUNICATION -----------------------------//
// this is the websocket event handler and say if someone connects
// as long as someone is connected, listen for messages
io.on('connect', function(socket) {
  console.log('a new user connected');
  var questionNum = 0; // keep count of question, used for IF condition.
  var score = 0;
  socket.on('loaded', function() { // we wait until the client has loaded and contacted us that it is ready to go.

    socket.emit('answer', "Hey! Want to know which animal you resemble the most among Tiger, Rabit, Panda and Koala?"); //We start with the introduction;
    setTimeout(timedQuestion, 5000, socket, "Tell me your name"); // Wait a moment and respond with a question.

  });
  socket.on('message', (data) => { // If we get a new message from the client we process it;
    console.log(data);
    [questionNum, score] = bot(data, socket, questionNum, score); // run the bot function with the new message
  });
  socket.on('disconnect', function() { // This function  gets called when the browser window gets closed
    console.log('user disconnected');
  });
});
//--------------------------CHAT BOT FUNCTION-------------------------------//
function bot(data, socket, questionNum, score) {
  var input = data; // This is generally really terrible from a security point of view ToDo avoid code injection
  var answer;
  var question;
  var waitTime;
  
  var name;

  /// These are the main statments that make up the conversation.
  if (questionNum == 0) { //Travel
    answer = 'Okay ' + input + ', let us start! :-)'; // output response
    waitTime = 5000;
    question = 'Do you like travel?'; // load next question
  } else if (questionNum == 1) { //Movie
    //socket.emit('changeFont', 'white');
    if (input.toLowerCase() === 'yes' || input === 1) {
      answer = 'Awesome! That is one thing we have in common!';
      waitTime = 5000;
      score = score + 1;
      question = 'Do you like romance movie or action movie?';
      socket.emit('changeBG', 'pink');
    } else if (input.toLowerCase() === 'no' || input === 0) {
      answer = 'Well okay :(  ....I really like to travel'
      waitTime = 5000;
      question = 'Do you like romance movie or action movie?';
      socket.emit('changeBG', 'pink');
    } else {
      question = 'Do you like travel?'; // load next question
      answer = 'I did not understand you. Could you please answer "yes" or "no"?'
      questionNum--;
      waitTime = 5000;
    }
  } else if (questionNum == 2) { // In person/ text
    
    if (input.toLowerCase() === 'romance' || input.toLowerCase() === 'romance movie') {
      answer = 'Good to know~';
      waitTime = 5000;
      question = 'In which way do you usually communicate with people? A.in person  B.text/email ';
     
      socket.emit('changeBG', 'grey');
      socket.emit('changeFont', 'white');
    } else if (input.toLowerCase() === 'action' || input.toLowerCase() === 'action movie') {
      answer = 'Awesome! That is another thing we have in common!'
      waitTime = 5000;
      score = score + 1;
      question = 'In which way do you usually communicate with people? A.in person  B.text/email ';
      
      socket.emit('changeBG', 'grey');
      socket.emit('changeFont', 'white');
    } else {
      question = 'Do you like romance movie or action movie?'; // load next question
      answer = 'I did not understand you. Could you please answer "romance" or "action"?'
      questionNum--;
      waitTime = 5000;
    }
  } else if (questionNum == 3) { // food
    
    if (input.toLowerCase() === 'a' || input === 1) {
      answer = 'So you are an extrovert person I assume!';
      waitTime = 5000;
      score = score + 1;
      question = 'Do you like salad or burger?';
      socket.emit('changeBG', 'green');
      socket.emit('changeFont', 'white');
    } else if (input.toLowerCase() === 'b' || input === 0) {
      answer = 'So you are an introvert person I assume!'
      waitTime = 5000;
      question = 'Do you like salad or burger?';
      socket.emit('changeBG', 'green');
      socket.emit('changeFont', 'white');
    } else {
      question = 'In which way do you usually communicate with people? A.in person  B.text/email '; // load next question
      answer = 'I did not understand you. Could you please answer "A" or "B"?'
      questionNum--;
      waitTime = 5000;
    }
  } else if (questionNum == 4) { // dogs/cats
    if (input.toLowerCase() === 'salad' || input === 1) {
      answer = 'Awesome! That is the third thing we have in common!!';
      waitTime = 5000;
      question = 'Do you like dogs or cats?';
      socket.emit('changeBG', 'purple');
      socket.emit('changeFont', 'white');
    } else if (input.toLowerCase() === 'burger' || input === 0) {
      answer = 'The Cafe at Bloomberg serves decent burger every Friday. Check that out!'
      waitTime = 5000;
      score = score + 1;
      question = 'Do you like dogs or cats?';
      socket.emit('changeBG', 'purple');
      socket.emit('changeFont', 'white');
    } else {
      question = 'Do you like salad or burger?'; // load next question
      answer = 'I did not understand you. Could you please answer "salad" or "burger"?'
      questionNum--;
      waitTime = 5000;
    }
  } else {
    if (input.toLowerCase() === 'dogs' || input.toLowerCase() === 'dog') {
      score = score;
      socket.emit('changeBG', 'Yellow');
      socket.emit('changeFont', 'black');
      if (score === 0) {
        answer = 'Wow! You are a Koala!'; // output response
        waitTime = 5000;
        question = '';
      } else if (score === 2 || score === 1) {
        answer = 'Wow! You are a Rabit!'; // output response
        waitTime = 5000;
        question = '';
      } else if (score === 4 || score === 3) {
        answer = 'Wow! You are a Panda!'; // output response
        waitTime = 5000;
        question = '';
      } else if (score == 5){
        answer = 'Wow! You are a Tiger!'; // output response
        waitTime = 5000;
        question = '';
      }
    } else if (input.toLowerCase() === 'cats' || input.toLowerCase() === 'cat') {
      score = score + 1;
      socket.emit('changeBG', 'Yellow');
      socket.emit('changeFont', 'black');
      if (score === 0) {
        answer = 'Wow! You are a Koala!'; // output response
        waitTime = 5000;
        question = '';
      } else if (score === 2 || score === 1) {
        answer = 'Wow! You are a Rabit!'; // output response
        waitTime = 5000;
        question = '';
      } else if (score === 4 || score === 3) {
        answer = 'Wow! You are a Panda!'; // output response
        waitTime = 5000;
        question = '';
      } else if (score === 5){
        answer = 'Wow! You are a Tiger!'; // output response
        waitTime = 5000;
        question = '';
      }
    } else {
      question = 'Do you like dogs or cats?'; // load next question
      answer = 'I did not understand you. Could you please answer "dog" or "cat"?'
      questionNum--;
      waitTime = 5000;
    }
  }


  /// We take the changed data and distribute it across the required objects.
  socket.emit('answer', answer);
  setTimeout(timedQuestion, waitTime, socket, question);
  return [(questionNum + 1), score];
}

function timedQuestion(socket, question) {
  if (question != '') {
    socket.emit('question', question);
  } else {
    //console.log('No Question send!');
  }

}
//----------------------------------------------------------------------------//
