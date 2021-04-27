
const config = require('../config/config.js');

var MongoClient = require('mongodb').MongoClient;
var url = config.mongourl;

var connected = false;
exports.db = null;

/* Init databáze */
exports.init =  function(callback = null) {
  MongoClient.connect(url, function(err, database) {
    connected = true;
    exports.db = database;

    console.log("DB Connected")

    if(typeof callback == "function") callback();
    });
}
