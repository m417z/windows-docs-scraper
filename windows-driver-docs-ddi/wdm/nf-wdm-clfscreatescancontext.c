CLFSUSER_API NTSTATUS ClfsCreateScanContext(
  [in]      PLOG_FILE_OBJECT   plfoLog,
  [in]      ULONG              cFromContainer,
  [in]      ULONG              cContainers,
  [in]      CLFS_SCAN_MODE     eScanMode,
  [in, out] PCLFS_SCAN_CONTEXT pcxScan
);