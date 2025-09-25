typedef struct _INTERNET_CACHE_CONFIG_INFOA {
  DWORD dwStructSize;
  DWORD dwContainer;
  DWORD dwQuota;
  DWORD dwReserved4;
  BOOL  fPerUser;
  DWORD dwSyncMode;
  DWORD dwNumCachePaths;
  union {
    struct {
      CHAR  CachePath[MAX_PATH];
      DWORD dwCacheSize;
    };
    INTERNET_CACHE_CONFIG_PATH_ENTRYA CachePaths[ANYSIZE_ARRAY];
  };
  DWORD dwNormalUsage;
  DWORD dwExemptUsage;
} INTERNET_CACHE_CONFIG_INFOA, *LPINTERNET_CACHE_CONFIG_INFOA;