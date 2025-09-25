BOOLEAN FsRtlFindInTunnelCache(
  [in]      TUNNEL         *Cache,
            ULONGLONG      DirectoryKey,
  [in]      UNICODE_STRING *Name,
  [out]     UNICODE_STRING *ShortName,
  [out]     UNICODE_STRING *LongName,
  [in, out] ULONG          *DataLength,
  [out]     VOID           *Data
);