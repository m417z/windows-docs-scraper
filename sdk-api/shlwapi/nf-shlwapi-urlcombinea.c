LWSTDAPI UrlCombineA(
  [in]            PCSTR pszBase,
  [in]            PCSTR pszRelative,
  [out, optional] PSTR  pszCombined,
  [in, out]       DWORD *pcchCombined,
                  DWORD dwFlags
);