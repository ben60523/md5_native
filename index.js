var { md5File, md5Str } = require('bindings')('md5_native');

module.exports = {
    withFile: function (path) {
        return md5File(path);
    },
    withStr: function (str) {
        return md5Str(str);
    }
}