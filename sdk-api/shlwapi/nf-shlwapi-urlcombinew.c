LWSTDAPI UrlCombineW(
  [in]            PCWSTR pszBase,
  [in]            PCWSTR pszRelative,
  [out, optional] PWSTR  pszCombined,
  [in, out]       DWORD  *pcchCombined,
                  DWORD  dwFlags
);