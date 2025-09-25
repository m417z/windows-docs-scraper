typedef struct _CMSG_HASHED_ENCODE_INFO {
  DWORD                      cbSize;
  HCRYPTPROV_LEGACY          hCryptProv;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  void                       *pvHashAuxInfo;
} CMSG_HASHED_ENCODE_INFO, *PCMSG_HASHED_ENCODE_INFO;