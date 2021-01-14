var md5 = require("./index");
var path = require("path")
console.log(md5.withStr("Hello, World!"))
console.log(md5.withFile(path.resolve("./README.md")))