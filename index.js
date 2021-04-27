
const mongo_driver = require('./modules/mongo');
const udp_driver = require('./modules/udp_driver');
const udp_router = require('./app/router');


mongo_driver.init(
  udp_driver.init(
    udp_router
  )
);
