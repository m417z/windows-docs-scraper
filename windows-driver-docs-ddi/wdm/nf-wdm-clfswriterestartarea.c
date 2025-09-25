CLFSUSER_API NTSTATUS ClfsWriteRestartArea(
  [in, out]       PVOID     pvMarshalContext,
  [in]            PVOID     pvRestartBuffer,
  [in]            ULONG     cbRestartBuffer,
  [in, optional]  PCLFS_LSN plsnBase,
  [in]            ULONG     fFlags,
  [out, optional] PULONG    pcbWritten,
  [out, optional] PCLFS_LSN plsnNext
);