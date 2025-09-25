DWORD ResUtilSetBinaryValue(
  [in]                HKEY         hkeyClusterKey,
  [in]                LPCWSTR      pszValueName,
  [in]                const LPBYTE pbNewValue,
  [in]                DWORD        cbNewValueSize,
  [in, out, optional] LPBYTE       *ppbOutValue,
  [in, out]           LPDWORD      pcbOutValueSize
);