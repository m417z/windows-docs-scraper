typedef struct _CRYPT_HASH_MESSAGE_PARA {
  DWORD                      cbSize;
  DWORD                      dwMsgEncodingType;
  HCRYPTPROV_LEGACY          hCryptProv;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  void                       *pvHashAuxInfo;
} CRYPT_HASH_MESSAGE_PARA, *PCRYPT_HASH_MESSAGE_PARA;