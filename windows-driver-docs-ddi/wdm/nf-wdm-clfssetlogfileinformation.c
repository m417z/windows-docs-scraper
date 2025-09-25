CLFSUSER_API NTSTATUS ClfsSetLogFileInformation(
  [in] PLOG_FILE_OBJECT           plfoLog,
  [in] CLFS_LOG_INFORMATION_CLASS eInformationClass,
  [in] PVOID                      pinfoBuffer,
  [in] ULONG                      cbBuffer
);