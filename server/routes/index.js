var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/api/message', function(req, res, next) {

	request({
		url: "https://api.particle.io/v1/devices/stranger_electron/message",
		method: "POST",
		form: {
			arg: request.body,
			access_token: process.env.PARTICLE_ACCESS_TOKEN
		}
	}, function (error, response, body) {

		if (error) {
			res.send("<Response><Message>Something went wrong...</Message></Response>");
		}
		else {
			res.send("<Response><Message>Got it!</Message></Response>");
		}
	});
});


module.exports = router;
