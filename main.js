
const express = require('express')
const app = express()

var MongoClient = require('mongodb').MongoClient;
var url = 'mongodb://localhost/smartcave';

MongoClient.connect(url, function(err, db) {

    var cursor = db.collection('cards').find();

    cursor.each(function(err, doc) {

    });




    var udp = require('dgram');

    var server = udp.createSocket('udp4');


    // emits on new datagram msg
    server.on('message',function(msg,info){
      console.log('Data received from client : ' + msg.toString());
      console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);



      db.collection('cards').insertOne({
        id : msg.toString().split("|")[3]
      })

    });


    //emits when socket is ready and listening for datagram msgs
    server.on('listening',function(){
      var address = server.address();
      var port = address.port;
      var family = address.family;
      var ipaddr = address.address;
      console.log('Server is listening at port' + port);
      console.log('Server ip :' + ipaddr);
      console.log('Server is IP4/IP6 : ' + family);
    });

    //emits after the socket is closed using socket.close();
    server.on('close',function(){
      console.log('Socket is closed !');
    });

    server.bind(4210);

});
