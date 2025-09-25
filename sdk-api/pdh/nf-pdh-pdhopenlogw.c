PDH_FUNCTION PdhOpenLogW(
  [in]  LPCWSTR    szLogFileName,
  [in]  DWORD      dwAccessFlags,
  [in]  LPDWORD    lpdwLogType,
  [in]  PDH_HQUERY hQuery,
  [in]  DWORD      dwMaxSize,
  [in]  LPCWSTR    szUserCaption,
  [out] PDH_HLOG   *phLog
);