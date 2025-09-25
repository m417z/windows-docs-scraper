CLFSUSER_API BOOL CreateLogContainerScanContext(
  [in]                HANDLE             hLog,
  [in]                ULONG              cFromContainer,
  [in]                ULONG              cContainers,
  [in]                CLFS_SCAN_MODE     eScanMode,
  [in, out]           PCLFS_SCAN_CONTEXT pcxScan,
  [in, out, optional] LPOVERLAPPED       pOverlapped
);