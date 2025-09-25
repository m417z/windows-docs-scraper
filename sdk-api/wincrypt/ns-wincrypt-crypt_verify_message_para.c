typedef struct _CRYPT_VERIFY_MESSAGE_PARA {
  DWORD                            cbSize;
  DWORD                            dwMsgAndCertEncodingType;
  HCRYPTPROV_LEGACY                hCryptProv;
  PFN_CRYPT_GET_SIGNER_CERTIFICATE pfnGetSignerCertificate;
  void                             *pvGetArg;
  PCCERT_STRONG_SIGN_PARA          pStrongSignPara;
} CRYPT_VERIFY_MESSAGE_PARA, *PCRYPT_VERIFY_MESSAGE_PARA;