DWORD ResUtilSetValueEx(
  [in] HKEY         hkeyClusterKey,
  [in] LPCWSTR      valueName,
  [in] DWORD        valueType,
  [in] const LPBYTE valueData,
  [in] DWORD        valueSize,
  [in] DWORD        flags
);