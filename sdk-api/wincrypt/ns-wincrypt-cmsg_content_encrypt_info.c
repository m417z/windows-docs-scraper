typedef struct _CMSG_CONTENT_ENCRYPT_INFO {
  DWORD                       cbSize;
  HCRYPTPROV_LEGACY           hCryptProv;
  CRYPT_ALGORITHM_IDENTIFIER  ContentEncryptionAlgorithm;
  void                        *pvEncryptionAuxInfo;
  DWORD                       cRecipients;
  PCMSG_RECIPIENT_ENCODE_INFO rgCmsRecipients;
  PFN_CMSG_ALLOC              pfnAlloc;
  PFN_CMSG_FREE               pfnFree;
  DWORD                       dwEncryptFlags;
  union {
    HCRYPTKEY         hContentEncryptKey;
    BCRYPT_KEY_HANDLE hCNGContentEncryptKey;
  } DUMMYUNIONNAME;
  DWORD                       dwFlags;
  BOOL                        fCNG;
  BYTE                        *pbCNGContentEncryptKeyObject;
  BYTE                        *pbContentEncryptKey;
  DWORD                       cbContentEncryptKey;
} CMSG_CONTENT_ENCRYPT_INFO, *PCMSG_CONTENT_ENCRYPT_INFO;