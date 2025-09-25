DOT11EXT_NIC_SPECIFIC_EXTENSION Dot11extNicSpecificExtension;

DWORD Dot11extNicSpecificExtension(
  [in, optional] HANDLE hDot11SvcHandle,
  [in]           DWORD dwInBufferSize,
  [in]           LPVOID pvInBuffer,
  [in, out]      DWORD *pdwOutBufferSize,
  [out]          LPVOID pvOutBuffer
)
{...}