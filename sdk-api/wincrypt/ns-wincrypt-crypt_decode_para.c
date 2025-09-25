typedef struct _CRYPT_DECODE_PARA {
  DWORD           cbSize;
  PFN_CRYPT_ALLOC pfnAlloc;
  PFN_CRYPT_FREE  pfnFree;
} CRYPT_DECODE_PARA, *PCRYPT_DECODE_PARA;