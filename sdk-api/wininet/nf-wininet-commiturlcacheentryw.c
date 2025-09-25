BOOL CommitUrlCacheEntryW(
  [in] LPCWSTR  lpszUrlName,
  [in] LPCWSTR  lpszLocalFileName,
  [in] FILETIME ExpireTime,
  [in] FILETIME LastModifiedTime,
  [in] DWORD    CacheEntryType,
  [in] LPWSTR   lpszHeaderInfo,
  [in] DWORD    cchHeaderInfo,
  [in] LPCWSTR  lpszFileExtension,
  [in] LPCWSTR  lpszOriginalUrl
);