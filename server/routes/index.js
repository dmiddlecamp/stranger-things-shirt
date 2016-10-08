var express = require('express');
var router = express.Router();
var request = require('request');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

//var access_token = "___";
var access_token = process.env.PARTICLE_ACCESS_TOKEN;


router.get('/api/message', function(req, res, next) {
	var message = req.param.message.toLowerCase();

	request({
		url: "https://api.particle.io/v1/devices/stranger_electron/message",
		method: "POST",
//		params: {
//			access_token: access_token
//		},
		form: {
			arg: message,
			access_token: access_token
		}
	}, function (error, response, body) {

		console.log("sent ", message, " particle response was ", body);

		if (error) {
			res.send("<Response><Message>Something went wrong...</Message></Response>");
		}
		else {
			res.send("<Response><Message>Got it!</Message></Response>");
		}
	});
});


router.post('/api/message', function(req, res, next) {
	var message = req.body.Body.toLowerCase();

	request({
		url: "https://api.particle.io/v1/devices/stranger_electron/message",
		method: "POST",
		form: {
			arg: message,
			access_token: access_token
		}
	}, function (error, response, body) {

		console.log("sent ", message, " particle response was ", body);

		if (error) {
			res.send("<Response><Message>Something went wrong...</Message></Response>");
		}
		else {

			res.send("<Response><Message>Got it!</Message></Response>");
		}
	});
});


module.exports = router;
