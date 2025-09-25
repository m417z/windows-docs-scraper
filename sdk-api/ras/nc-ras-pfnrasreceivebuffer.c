PFNRASRECEIVEBUFFER Pfnrasreceivebuffer;

DWORD Pfnrasreceivebuffer(
  HANDLE hPort,
  PBYTE pBuffer,
  PDWORD pdwSize,
  DWORD dwTimeOut,
  HANDLE hEvent
)
{...}