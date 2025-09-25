typedef struct _CMSG_SIGNER_ENCODE_INFO {
  DWORD                      cbSize;
  PCERT_INFO                 pCertInfo;
  union {
    HCRYPTPROV        hCryptProv;
    NCRYPT_KEY_HANDLE hNCryptKey;
    BCRYPT_KEY_HANDLE hBCryptKey;
  } DUMMYUNIONNAME;
  DWORD                      dwKeySpec;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  void                       *pvHashAuxInfo;
  DWORD                      cAuthAttr;
  PCRYPT_ATTRIBUTE           rgAuthAttr;
  DWORD                      cUnauthAttr;
  PCRYPT_ATTRIBUTE           rgUnauthAttr;
  CERT_ID                    SignerId;
  CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
  void                       *pvHashEncryptionAuxInfo;
} CMSG_SIGNER_ENCODE_INFO, *PCMSG_SIGNER_ENCODE_INFO;