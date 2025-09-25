int GetDateFormatEx(
  [in, optional]  LPCWSTR          lpLocaleName,
  [in]            DWORD            dwFlags,
  [in, optional]  const SYSTEMTIME *lpDate,
  [in, optional]  LPCWSTR          lpFormat,
  [out, optional] LPWSTR           lpDateStr,
  [in]            int              cchDate,
  [in, optional]  LPCWSTR          lpCalendar
);