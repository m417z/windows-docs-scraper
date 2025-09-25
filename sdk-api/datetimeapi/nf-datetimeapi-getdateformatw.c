int GetDateFormatW(
  [in]            LCID             Locale,
  [in]            DWORD            dwFlags,
  [in, optional]  const SYSTEMTIME *lpDate,
  [in, optional]  LPCWSTR          lpFormat,
  [out, optional] LPWSTR           lpDateStr,
  [in]            int              cchDate
);