VOID FsRtlAddToTunnelCache(
  [in] TUNNEL         *Cache,
  [in] ULONGLONG      DirectoryKey,
  [in] UNICODE_STRING *ShortName,
  [in] UNICODE_STRING *LongName,
  [in] BOOLEAN        KeyByShortName,
  [in] ULONG          DataLength,
  [in] VOID           *Data
);