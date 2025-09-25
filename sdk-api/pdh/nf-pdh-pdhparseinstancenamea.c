PDH_FUNCTION PdhParseInstanceNameA(
  [in]      LPCSTR  szInstanceString,
  [out]     LPSTR   szInstanceName,
  [in, out] LPDWORD pcchInstanceNameLength,
  [out]     LPSTR   szParentName,
  [in, out] LPDWORD pcchParentNameLength,
  [out]     LPDWORD lpIndex
);