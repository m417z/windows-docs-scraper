int FindNLSString(
  [in]            LCID    Locale,
  [in]            DWORD   dwFindNLSStringFlags,
  [in]            LPCWSTR lpStringSource,
  [in]            int     cchSource,
  [in]            LPCWSTR lpStringValue,
  [in]            int     cchValue,
  [out, optional] LPINT   pcchFound
);