const config = require('../config/config.js');
var udp = require('dgram');
var server = udp.createSocket('udp4');

/* Init databáze */
exports.init =  function(router, callback = null) {
  //event, který proběhne pokud začne server naslouchat
  server.on('listening',function(){
    var address = server.address();
    var port = address.port;
    var family = address.family;
    var ipaddr = address.address;
    console.log('Server is listening at port ' + port);
    console.log('Server ip :' + ipaddr);
    console.log('Server is IP4/IP6 : ' + family);


      // event, pokud příjde UDP paket
      server.on('message',function(msg,info){

        // Rosekání requestu na metodu a atributy a odeslání do routeru
        var udp_parts = msg.toString().split("|");
        if(udp_parts.length > 1) {
          if(udp_parts.length > 3){

            var attr = [];
            for(var i = 3; i < udp_parts.length; i++){
              attr.push(udp_parts[i]);
            }

            router.route(udp_parts[0], udp_parts[1], udp_parts[2], attr);

          } else {
            if(udp_parts.length > 2){
              router.route(udp_parts[0], udp_parts[1], udp_parts[2]);
            } else {
              router.route(udp_parts[0], udp_parts[1]);
            }
          }
        } else {
          // Chybný request
        }
      });

    if(typeof callback == "function") callback();
  });

  //event který proběhne když  se socket zavře pomocí socket.close();
  server.on('close',function(){
    console.log('Socket is closed !');
  });

  server.bind(config.udp_port);

}

exports.sendRequest = function(device, method, name = null, parameters = []){

  var message = device + "|" + method;
  if(name !== null) message += "|" + name;

  if(parameters.length > 0){
    for(var i = 0; i < parameters.length; i++){
      message += "|" + parameters[i];
    }
  }
console.log(message);
  var client = udp.createSocket('udp4');

  client.bind(function () {
    client.setBroadcast(true);
  });

    client.send(message, 0, message.length, config.udp_port, config.broadcast_id, (err) => {
      client.close();
     });

  

}
exports.sendInfo = function(parameters = []){

  var message = "INFO" + "|" + config.device_name;

  if(parameters.length > 0){
    for(var i = 0; i < parameters.length; i++){
      message += "|" + parameters[i];
    }
  }

  var client = udp.createSocket('udp4');
    client.send(message, config.udp_port, config.broadcast_id, (err) => {
    client.close();
  });
  client.close();

}

exports.sendRaw = function(message){

  var client = udp.createSocket('udp4');
    client.send(message, config.udp_port, config.broadcast_id, (err) => {
    client.close();
  });
  client.close();

}
