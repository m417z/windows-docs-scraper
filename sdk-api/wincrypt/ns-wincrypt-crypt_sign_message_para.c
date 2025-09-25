typedef struct _CRYPT_SIGN_MESSAGE_PARA {
  DWORD                      cbSize;
  DWORD                      dwMsgEncodingType;
  PCCERT_CONTEXT             pSigningCert;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  void                       *pvHashAuxInfo;
  DWORD                      cMsgCert;
  PCCERT_CONTEXT             *rgpMsgCert;
  DWORD                      cMsgCrl;
  PCCRL_CONTEXT              *rgpMsgCrl;
  DWORD                      cAuthAttr;
  PCRYPT_ATTRIBUTE           rgAuthAttr;
  DWORD                      cUnauthAttr;
  PCRYPT_ATTRIBUTE           rgUnauthAttr;
  DWORD                      dwFlags;
  DWORD                      dwInnerContentType;
  CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
  void                       *pvHashEncryptionAuxInfo;
} CRYPT_SIGN_MESSAGE_PARA, *PCRYPT_SIGN_MESSAGE_PARA;