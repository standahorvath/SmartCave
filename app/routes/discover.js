const configLogic = require('./../../config/logic.js');
const udp_driver = require('./../../modules/udp_driver');

exports.route =  async function(method, parameters = []) {
  if(typeof exports[method] != "undefined") {
    return await exports[method](parameters);
  }
}

exports.DEVICE = async function(parameters = []){

  udp_driver.sendInfo(['DISCOVER'])

  return null;

}
