/**** Webserver Setup ****/
var shell = require('shelljs');
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
	var comando = req.query.command;
	console.log(req.query.command);
	//Se existe alguma entrada de dados
	if(typeof comando !== 'undefined'){
		//Configuração do shell exec
		var execOptions = {
			async: true,
			silent: false,
			encoding: 'utf8'
		};
		//Escolha do comando
		var output = "./scriptsCpp/teste a";
		switch (comando) {
			case 'esquerda':
				output += "e";
				break;
			case 'direita':
				output += "d";
				break;
			case 'frente':
				output += "f";
				break;
			case 'parar':
				output += "p";
				break;
		}
		shell.exec(output,execOptions,function(){
			//CALLBACK
		});
	}
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
