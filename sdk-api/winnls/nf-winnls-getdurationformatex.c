int GetDurationFormatEx(
  [in, optional]  LPCWSTR          lpLocaleName,
  [in]            DWORD            dwFlags,
  [in, optional]  const SYSTEMTIME *lpDuration,
  [in]            ULONGLONG        ullDuration,
  [in, optional]  LPCWSTR          lpFormat,
  [out, optional] LPWSTR           lpDurationStr,
  [in]            int              cchDuration
);