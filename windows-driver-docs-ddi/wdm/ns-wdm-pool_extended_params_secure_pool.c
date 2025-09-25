typedef struct _POOL_EXTENDED_PARAMS_SECURE_POOL {
  HANDLE    SecurePoolHandle;
  PVOID     Buffer;
  ULONG_PTR Cookie;
  ULONG     SecurePoolFlags;
} POOL_EXTENDED_PARAMS_SECURE_POOL;