typedef struct _INTERNET_CACHE_ENTRY_INFOW {
  DWORD    dwStructSize;
  LPWSTR   lpszSourceUrlName;
  LPWSTR   lpszLocalFileName;
  DWORD    CacheEntryType;
  DWORD    dwUseCount;
  DWORD    dwHitRate;
  DWORD    dwSizeLow;
  DWORD    dwSizeHigh;
  FILETIME LastModifiedTime;
  FILETIME ExpireTime;
  FILETIME LastAccessTime;
  FILETIME LastSyncTime;
  LPWSTR   lpHeaderInfo;
  DWORD    dwHeaderInfoSize;
  LPWSTR   lpszFileExtension;
  union {
    DWORD dwReserved;
    DWORD dwExemptDelta;
  };
} INTERNET_CACHE_ENTRY_INFOW, *LPINTERNET_CACHE_ENTRY_INFOW;