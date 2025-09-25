DWORD XcvDataPort(
  _In_  HANDLE  hXcv,
  _In_  LPCWSTR pszDataName,
  _In_  PBYTE   pInputData,
        DWORD   cbInputData,
  _Out_ PBYTE   pOutputData,
        DWORD   cbOutputData,
  _Out_ PDWORD  pcbOutputNeeded
);