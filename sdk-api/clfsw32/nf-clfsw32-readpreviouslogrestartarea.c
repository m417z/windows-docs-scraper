CLFSUSER_API BOOL ReadPreviousLogRestartArea(
  [in]                PVOID        pvReadContext,
  [out]               PVOID        *ppvRestartBuffer,
  [out]               PULONG       pcbRestartBuffer,
  [out]               PCLFS_LSN    plsnRestart,
  [in, out, optional] LPOVERLAPPED pOverlapped
);