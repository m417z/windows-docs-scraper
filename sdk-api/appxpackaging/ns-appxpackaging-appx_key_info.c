typedef struct APPX_KEY_INFO {
  UINT32 keyLength;
  UINT32 keyIdLength;
  BYTE   *key;
  BYTE   *keyId;
} APPX_KEY_INFO;