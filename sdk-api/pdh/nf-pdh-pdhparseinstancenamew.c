PDH_FUNCTION PdhParseInstanceNameW(
  [in]      LPCWSTR szInstanceString,
  [out]     LPWSTR  szInstanceName,
  [in, out] LPDWORD pcchInstanceNameLength,
  [out]     LPWSTR  szParentName,
  [in, out] LPDWORD pcchParentNameLength,
  [out]     LPDWORD lpIndex
);