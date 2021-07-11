const express = require('express')
const app = express(80)

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
