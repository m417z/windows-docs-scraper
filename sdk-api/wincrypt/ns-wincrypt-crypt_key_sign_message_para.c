typedef struct _CRYPT_KEY_SIGN_MESSAGE_PARA {
  DWORD                      cbSize;
  DWORD                      dwMsgAndCertEncodingType;
  union {
    HCRYPTPROV        hCryptProv;
    NCRYPT_KEY_HANDLE hNCryptKey;
  } DUMMYUNIONNAME;
  DWORD                      dwKeySpec;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  void                       *pvHashAuxInfo;
  CRYPT_ALGORITHM_IDENTIFIER PubKeyAlgorithm;
} CRYPT_KEY_SIGN_MESSAGE_PARA, *PCRYPT_KEY_SIGN_MESSAGE_PARA;