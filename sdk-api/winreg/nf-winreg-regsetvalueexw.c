LSTATUS RegSetValueExW(
  [in]           HKEY       hKey,
  [in, optional] LPCWSTR    lpValueName,
                 DWORD      Reserved,
  [in]           DWORD      dwType,
  [in]           const BYTE *lpData,
  [in]           DWORD      cbData
);