typedef struct NCRYPT_ALLOC_PARA {
  DWORD            cbSize;
  PFN_NCRYPT_ALLOC pfnAlloc;
  PFN_NCRYPT_FREE  pfnFree;
} NCRYPT_ALLOC_PARA;