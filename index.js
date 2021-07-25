const express = require('express')
const app = express()

const mongo_driver = require('./modules/mongo');
const udp_driver = require('./modules/udp_driver');
const udp_router = require('./app/router');


app.get('/', (req, res) => {
  res.sendFile( __dirname + "/static/" + "index.html" );
})

var server = app.listen(80, function () {
  var host = server.address().address
  var port = server.address().port
  
  console.log("Website http://%s:%s", host, port)
})

mongo_driver.init(
  udp_driver.init(
    udp_router
  )
);


/* 

  SmartCave project
  Smartcave is a opensource project for smarthome Trigger&Event actions.
  This system can listen on UDP actions of devices in LAN and react on it by configuration im /config/logic.js

  DEVICES:

  DEVICE: KEYGUARD
  DESCRIPTION: Arduino based device with RFID reader.
  UDP_PACKET_EXAMPLE: KEYGUARD|RFID|MIFARE 1KB|4ABFBA12




*/