typedef struct _CRYPT_ENCRYPT_MESSAGE_PARA {
  DWORD                      cbSize;
  DWORD                      dwMsgEncodingType;
  HCRYPTPROV_LEGACY          hCryptProv;
  CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
  void                       *pvEncryptionAuxInfo;
  DWORD                      dwFlags;
  DWORD                      dwInnerContentType;
} CRYPT_ENCRYPT_MESSAGE_PARA, *PCRYPT_ENCRYPT_MESSAGE_PARA;