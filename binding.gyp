{
  "targets": [
    {
      "target_name": "md5_native",
      "sources": [
        "lib/md5.c",
        "src.cc" 
        ],
      "libraries": [
        "-ldbghelp.lib",
        "-lWS2_32.lib",
        "-ladvapi32.lib",
        "-luser32.lib",
        "-lIPHLPAPI.lib",
        "-lPSAPI.lib",
        "-lUSERENV.lib",
        "-lCRYPT32.lib",
        "-lbcrypt.lib",
        "-lkernel32.lib",
        "-lWINMM.lib"
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
