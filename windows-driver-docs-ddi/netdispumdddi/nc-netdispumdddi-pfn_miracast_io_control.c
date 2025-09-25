PFN_MIRACAST_IO_CONTROL PfnMiracastIoControl;

NTSTATUS PfnMiracastIoControl(
  [in]            HANDLE hMiracastDeviceHandle,
  [in]            BOOL HardwareAccess,
  [in]            UINT InputBufferSize,
  [in]            VOID *pInputBuffer,
  [in]            UINT OutputBufferSize,
  [out]           VOID *pOutputBuffer,
  [out, optional] UINT *pBytesReturned
)
{...}