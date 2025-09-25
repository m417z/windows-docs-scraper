PDH_FUNCTION PdhOpenLogA(
  [in]  LPCSTR     szLogFileName,
  [in]  DWORD      dwAccessFlags,
  [in]  LPDWORD    lpdwLogType,
  [in]  PDH_HQUERY hQuery,
  [in]  DWORD      dwMaxSize,
  [in]  LPCSTR     szUserCaption,
  [out] PDH_HLOG   *phLog
);