const configLogic = require('./../../config/logic.js');
const cardModel = require('./../models/cardModel.js');
const udp_driver = require('./../../modules/udp_driver');

exports.route =  async function(method, parameters = []) {
  if(typeof exports[method] != "undefined") {
    return await exports[method](parameters);
  }
}

exports.RFID = async function(parameters = []){

  if(parameters.length > 1){
    await cardModel.addCartIfNotExist(parameters[1], parameters[0])

    var card = await cardModel.getCard(parameters[1])

    if(typeof card.name != "undefined" && typeof configLogic.cards != "undefined" && typeof configLogic.cards[card.name] != "undefined"){
      var commands = configLogic.cards[card.name];
      for(var i = 0; i < commands.length; i++){
        udp_driver.sendRequest(commands[i].device, commands[i].method, commands[i].parameters)
      }

      return commands;
    }
  }

  return null;

}
