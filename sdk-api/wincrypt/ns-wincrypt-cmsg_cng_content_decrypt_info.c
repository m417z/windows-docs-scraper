typedef struct _CMSG_CNG_CONTENT_DECRYPT_INFO {
  DWORD                      cbSize;
  CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
  PFN_CMSG_ALLOC             pfnAlloc;
  PFN_CMSG_FREE              pfnFree;
  NCRYPT_KEY_HANDLE          hNCryptKey;
  BYTE                       *pbContentEncryptKey;
  DWORD                      cbContentEncryptKey;
  BCRYPT_KEY_HANDLE          hCNGContentEncryptKey;
  BYTE                       *pbCNGContentEncryptKeyObject;
} CMSG_CNG_CONTENT_DECRYPT_INFO, *PCMSG_CNG_CONTENT_DECRYPT_INFO;