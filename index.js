/**** Webserver Setup ****/
var app = require('express')();
fs = require('fs');
app.set('view engine','ejs');



/**** Pages Declarations ****/
app.get('/', function(req,res){
	res.render("index");
})

/**** Pages Declarations ****/
app.get('/mover', function(req,res){
	res.render("mover");
})

app.get('/logo.png', function(req,res){
   console.log("Getting Logo Image..");
   var img = fs.readFileSync('images/pinima.png');
   res.writeHead(200, {'Content-Type': 'image/png' });
   res.end(img, 'binary');
})


/**** Start Webserver ****/
app.listen(3000, function(){
	console.log("Webserver at PORT 3000 running...");
});
