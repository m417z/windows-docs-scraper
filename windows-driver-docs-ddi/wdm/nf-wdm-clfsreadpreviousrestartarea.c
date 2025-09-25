CLFSUSER_API NTSTATUS ClfsReadPreviousRestartArea(
  [in]  PVOID     pvReadContext,
  [out] PVOID     *ppvRestartBuffer,
  [out] PULONG    pcbRestartBuffer,
  [out] PCLFS_LSN plsnRestart
);