int GetTimeFormatA(
  [in]            LCID             Locale,
  [in]            DWORD            dwFlags,
  [in, optional]  const SYSTEMTIME *lpTime,
  [in, optional]  LPCSTR           lpFormat,
  [out, optional] LPSTR            lpTimeStr,
  [in]            int              cchTime
);