CLFSUSER_API NTSTATUS ClfsQueryLogFileInformation(
  [in]  PLOG_FILE_OBJECT           plfoLog,
  [in]  CLFS_LOG_INFORMATION_CLASS eInformationClass,
        PVOID                      pinfoInputBuffer,
        ULONG                      cbinfoInputBuffer,
  [out] PVOID                      pinfoBuffer,
        PULONG                     pcbInfoBuffer
);