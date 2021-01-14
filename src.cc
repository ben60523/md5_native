#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
extern "C"
{
#include "md5.h"
}
#include <napi.h>
#include <string>

using namespace std;

Napi::String md5_file(const Napi::CallbackInfo &info)
{
  uint8_t *result;
  Napi::Env env = info.Env();
  std::string path_str = info[0].As<Napi::String>();
  if (path_str.length() == 0)
  {
    return Napi::String::New(env, "Error::Argument Not Set");
  }
  const char *path = path_str.c_str();
  FILE *fptr = fopen(path, "rb");
  if (fptr == NULL)
  {
    return Napi::String::New(env, "Error::Invalid File");
  }
  result = md5File(fptr);
  char md5_hash[33];
  for (int i = 0; i < 16; i++)
  {
    sprintf(&md5_hash[2 * i], "%02X", result[i]);
  }
  md5_hash[32] = '\0';
  fclose(fptr);
  free(result);
  return Napi::String::New(env, md5_hash);
}

Napi::String md5_str(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  uint8_t *result;
  std::string str = info[0].As<Napi::String>();
  int len = str.length();
  if (len == 0)
  {
    return Napi::String::New(env, "Error::Argument Not Set");
  }
  char *src = (char *)malloc(sizeof(char *) * (len + 1));
  strcpy(src, str.c_str());
  result = md5String(src);
  char md5_hash[33];
  for (int i = 0; i < 16; i++)
  {
    sprintf(&md5_hash[2 * i], "%02X", result[i]);
  }
  md5_hash[32] = '\0';
  free(src);
  return Napi::String::New(env, md5_hash);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "md5File"), Napi::Function::New(env, md5_file));
  exports.Set(Napi::String::New(env, "md5Str"), Napi::Function::New(env, md5_str));
  return exports;
}
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
