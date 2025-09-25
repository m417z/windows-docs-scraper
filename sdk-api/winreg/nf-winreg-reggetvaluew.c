LSTATUS RegGetValueW(
  [in]                HKEY    hkey,
  [in, optional]      LPCWSTR lpSubKey,
  [in, optional]      LPCWSTR lpValue,
  [in, optional]      DWORD   dwFlags,
  [out, optional]     LPDWORD pdwType,
  [out, optional]     PVOID   pvData,
  [in, out, optional] LPDWORD pcbData
);