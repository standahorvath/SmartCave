const mongo_driver = require('./../../modules/mongo');

/* Logování akce */
exports.addCartIfNotExist = async function(rfid, type){
  var cardObject = {
    "type": type,
    "rfid": rfid,
    "name": "",
    "created": new Date()
  }

  var result = await mongo_driver.db.collection('cards').find({"rfid": rfid}).toArray();

    if(result.length == 0){
      mongo_driver.db.collection('cards').insertOne(
        cardObject
      )
    }
}

exports.getCard = async function(rfid){
  return await mongo_driver.db.collection('cards').findOne({"rfid": rfid});
}
