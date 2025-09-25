int GetDateFormatA(
  [in]            LCID             Locale,
  [in]            DWORD            dwFlags,
  [in, optional]  const SYSTEMTIME *lpDate,
  [in, optional]  LPCSTR           lpFormat,
  [out, optional] LPSTR            lpDateStr,
  [in]            int              cchDate
);