const config = require('../config/config.js');
const logModel = require('./models/logModel.js');

// Routes
const keyguardRoute = require('./routes/keyguard.js');

exports.routes = {
  "KEYGUARD" : keyguardRoute
}

/* route metoda při příchodu requestu */
exports.route =  async function(device, method, parameters = []) {
  console.log("Zařízení: "+device);
  console.log("Metoda: "+method);
  console.log("Parametry "+parameters);



  var executed = [];

  if(typeof exports.routes[device] != "undefined"){
    executed = await exports.routes[device].route(method, parameters)
  }

  logModel.logRoute(device, method, parameters, executed);
}