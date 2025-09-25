CLFSUSER_API BOOL WriteLogRestartArea(
  [in, out]           PVOID        pvMarshal,
  [in]                PVOID        pvRestartBuffer,
  [in]                ULONG        cbRestartBuffer,
  [in, optional]      PCLFS_LSN    plsnBase,
  [in]                ULONG        fFlags,
  [out, optional]     PULONG       pcbWritten,
  [out, optional]     PCLFS_LSN    plsnNext,
  [in, out, optional] LPOVERLAPPED pOverlapped
);