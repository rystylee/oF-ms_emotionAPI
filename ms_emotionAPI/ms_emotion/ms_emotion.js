var request = require('request');
var fs = require('fs');
var osc = require('node-osc/lib');
var pushspace = new Boolean(false);

//emtion APIに送信する情報を取得する関数
function getProperty(){
    myImage = fs.readFileSync('../bin/data/myFace/myFace.jpg');
    options = {
        method: 'POST',
        url: 'https://api.projectoxford.ai/emotion/v1.0/recognize',
        headers: {
            'Content-Type': 'application/octet-stream',
            'Ocp-Apim-Subscription-Key': 'your Subscription-Key'
        },
        body: myImage
    };
};

var oscServer = new osc.Server(8000, '127.0.0.1');
oscServer.on('message', function(msg, rinfo){

    getProperty();
    //emotion APIに送信、JSONで結果を取得しファイルに書き込む
    request.post(options, function(error, response, body){
        if(!error && response.statusCode == 200){
            var object = JSON.parse(body);
            fs.writeFile('facedata.json', JSON.stringify(object));
            console.dir(object, {depth: null, colors: true});
        }
    });
});