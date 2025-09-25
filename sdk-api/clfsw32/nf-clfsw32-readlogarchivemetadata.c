CLFSUSER_API BOOL ReadLogArchiveMetadata(
  [in]      CLFS_LOG_ARCHIVE_CONTEXT pvArchiveContext,
  [in]      ULONG                    cbOffset,
  [in]      ULONG                    cbBytesToRead,
  [in, out] PBYTE                    pbReadBuffer,
  [out]     PULONG                   pcbBytesRead
);