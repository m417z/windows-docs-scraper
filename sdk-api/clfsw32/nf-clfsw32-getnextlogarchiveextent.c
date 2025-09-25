CLFSUSER_API BOOL GetNextLogArchiveExtent(
  [in]      CLFS_LOG_ARCHIVE_CONTEXT   pvArchiveContext,
  [in, out] CLFS_ARCHIVE_DESCRIPTOR [] rgadExtent,
  [in]      ULONG                      cDescriptors,
  [out]     PULONG                     pcDescriptorsReturned
);