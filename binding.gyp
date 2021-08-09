{
  "targets": [
    {
      "target_name": "md5_native",
      "sources": [
        "lib/md5.c",
        "src.cc" 
        ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "lib"
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ]
    }
  ]
}
