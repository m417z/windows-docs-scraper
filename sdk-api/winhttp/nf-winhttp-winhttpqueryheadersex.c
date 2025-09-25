WINHTTPAPI DWORD WinHttpQueryHeadersEx(
  HINTERNET                hRequest,
  DWORD                    dwInfoLevel,
  ULONGLONG                ullFlags,
  UINT                     uiCodePage,
  PDWORD                   pdwIndex,
  PWINHTTP_HEADER_NAME     pHeaderName,
  PVOID                    pBuffer,
  PDWORD                   pdwBufferLength,
  PWINHTTP_EXTENDED_HEADER *ppHeaders,
  PDWORD                   pdwHeadersCount
);