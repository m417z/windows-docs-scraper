DOT11EXTIHV_CONTROL Dot11extihvControl;

DWORD Dot11extihvControl(
  [in, optional]  HANDLE hIhvExtAdapter,
  [in]            DWORD dwInBufferSize,
  [in, optional]  PBYTE pInBuffer,
  [in]            DWORD dwOutBufferSize,
  [out, optional] PBYTE pOutBuffer,
  [out]           PDWORD pdwBytesReturned
)
{...}