int GetNumberFormatEx(
  [in, optional]  LPCWSTR          lpLocaleName,
  [in]            DWORD            dwFlags,
  [in]            LPCWSTR          lpValue,
  [in, optional]  const NUMBERFMTW *lpFormat,
  [out, optional] LPWSTR           lpNumberStr,
  [in]            int              cchNumber
);