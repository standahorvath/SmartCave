
const config = require('../config/config.js');

var MongoClient = require('mongodb').MongoClient;
var url = config.mongourl;

var connected = false;
exports.db = null;

/* Init databáze */
exports.init =  function(callback = null) {

  MongoClient.connect(url, (err, client) => {
    connected = true;

    // Client returned
    var db = client.db(config.db_name);
    exports.db = db;

    console.log("DB Connected")

    if(typeof callback == "function") callback();
    });

}
