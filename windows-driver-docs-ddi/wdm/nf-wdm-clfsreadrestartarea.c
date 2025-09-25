CLFSUSER_API NTSTATUS ClfsReadRestartArea(
  [in, out] PVOID     pvMarshalContext,
  [out]     PVOID     *ppvRestartBuffer,
  [out]     PULONG    pcbRestartBuffer,
  [out]     PCLFS_LSN plsn,
  [out]     PVOID     *ppvReadContext
);