int GetTimeFormatEx(
  [in, optional]  LPCWSTR          lpLocaleName,
  [in]            DWORD            dwFlags,
  [in, optional]  const SYSTEMTIME *lpTime,
  [in, optional]  LPCWSTR          lpFormat,
  [out, optional] LPWSTR           lpTimeStr,
  [in]            int              cchTime
);