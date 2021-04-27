const mongo_driver = require('./../../modules/mongo');

/* Logování akce */
exports.logRoute = function(device, method, parameters = [], executed = []){
  var logObject = {
    "type": "udp_request",
    "data": {
      "device": device,
      "method": method,
      "parameters": parameters,
      "executed" : executed
    },
    "captured": new Date()
  }
console.log(logObject);

  mongo_driver.db.collection('logs').insertOne(
    logObject
  )

}
