const config = require('../config/config.js');
const logModel = require('./models/logModel.js');

// Routes
const keyguardRoute = require('./routes/keyguard.js');
const discoverRoute = require('./routes/discover.js');

exports.routes = {
  "KEYGUARD" : keyguardRoute,
  "DISCOVER" : discoverRoute,
}

/* route metoda při příchodu requestu */
exports.route =  async function(device, method, name = "", parameters = []) {
  console.log("Zařízení: "+device);
  console.log("Metoda: "+method);
  console.log("Jméno: "+name);
  console.log("Parametry "+parameters);



  var executed = [];

  if(typeof exports.routes[device] != "undefined"){
    executed = await exports.routes[device].route(method, name, parameters)
  }

  logModel.logRoute(device, method, name, parameters, executed);
}
