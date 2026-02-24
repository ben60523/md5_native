import { createRequire } from 'module';
const require = createRequire(import.meta.url);

const { md5File, md5Str } = require('bindings')('md5_native');

export function withFile(path) {
  return md5File(path);
}

export function withStr(str) {
  return md5Str(str);
}

export default {
  withFile,
  withStr
};
