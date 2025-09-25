typedef struct _INTERNET_CACHE_ENTRY_INFOA {
  DWORD    dwStructSize;
  LPSTR    lpszSourceUrlName;
  LPSTR    lpszLocalFileName;
  DWORD    CacheEntryType;
  DWORD    dwUseCount;
  DWORD    dwHitRate;
  DWORD    dwSizeLow;
  DWORD    dwSizeHigh;
  FILETIME LastModifiedTime;
  FILETIME ExpireTime;
  FILETIME LastAccessTime;
  FILETIME LastSyncTime;
  LPSTR    lpHeaderInfo;
  DWORD    dwHeaderInfoSize;
  LPSTR    lpszFileExtension;
  union {
    DWORD dwReserved;
    DWORD dwExemptDelta;
  };
} INTERNET_CACHE_ENTRY_INFOA, *LPINTERNET_CACHE_ENTRY_INFOA;