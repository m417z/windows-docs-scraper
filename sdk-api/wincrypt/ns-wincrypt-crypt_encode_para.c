typedef struct _CRYPT_ENCODE_PARA {
  DWORD           cbSize;
  PFN_CRYPT_ALLOC pfnAlloc;
  PFN_CRYPT_FREE  pfnFree;
} CRYPT_ENCODE_PARA, *PCRYPT_ENCODE_PARA;