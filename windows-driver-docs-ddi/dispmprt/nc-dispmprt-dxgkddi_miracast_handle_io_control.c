DXGKDDI_MIRACAST_HANDLE_IO_CONTROL DxgkddiMiracastHandleIoControl;

NTSTATUS DxgkddiMiracastHandleIoControl(
  [in]  PVOID DriverContext,
  [in]  PVOID MiracastContext,
  [in]  ULONG InputBufferSize,
  [in]  VOID *pInputBuffer,
  [in]  ULONG OutputBufferSize,
  [out] VOID *pOutputBuffer,
  [out] ULONG *BytesReturned
)
{...}