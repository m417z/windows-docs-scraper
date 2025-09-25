BOOL CommitUrlCacheEntryA(
  [in] LPCSTR   lpszUrlName,
  [in] LPCSTR   lpszLocalFileName,
  [in] FILETIME ExpireTime,
  [in] FILETIME LastModifiedTime,
  [in] DWORD    CacheEntryType,
  [in] LPBYTE   lpHeaderInfo,
  [in] DWORD    cchHeaderInfo,
  [in] LPCSTR   lpszFileExtension,
  [in] LPCSTR   lpszOriginalUrl
);