int GetNumberFormatA(
  [in]            LCID             Locale,
  [in]            DWORD            dwFlags,
  [in]            LPCSTR           lpValue,
  [in, optional]  const NUMBERFMTA *lpFormat,
  [out, optional] LPSTR            lpNumberStr,
  [in]            int              cchNumber
);