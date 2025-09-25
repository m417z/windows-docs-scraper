LSTATUS RegGetValueA(
  [in]                HKEY    hkey,
  [in, optional]      LPCSTR  lpSubKey,
  [in, optional]      LPCSTR  lpValue,
  [in, optional]      DWORD   dwFlags,
  [out, optional]     LPDWORD pdwType,
  [out, optional]     PVOID   pvData,
  [in, out, optional] LPDWORD pcbData
);