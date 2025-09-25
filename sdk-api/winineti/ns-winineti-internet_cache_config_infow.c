typedef struct _INTERNET_CACHE_CONFIG_INFOW {
  DWORD dwStructSize;
  DWORD dwContainer;
  DWORD dwQuota;
  DWORD dwReserved4;
  BOOL  fPerUser;
  DWORD dwSyncMode;
  DWORD dwNumCachePaths;
  union {
    struct {
      WCHAR CachePath[MAX_PATH];
      DWORD dwCacheSize;
    };
    INTERNET_CACHE_CONFIG_PATH_ENTRYW CachePaths[ANYSIZE_ARRAY];
  };
  DWORD dwNormalUsage;
  DWORD dwExemptUsage;
} INTERNET_CACHE_CONFIG_INFOW, *LPINTERNET_CACHE_CONFIG_INFOW;