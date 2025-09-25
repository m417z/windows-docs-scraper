CLFSUSER_API BOOL ReadLogRestartArea(
  [in]                PVOID        pvMarshal,
  [out]               PVOID        *ppvRestartBuffer,
  [out]               PULONG       pcbRestartBuffer,
  [out]               PCLFS_LSN    plsn,
  [out]               PVOID        *ppvContext,
  [in, out, optional] LPOVERLAPPED pOverlapped
);