LWSTDAPI AssocQueryStringW(
  [in]            ASSOCF   flags,
  [in]            ASSOCSTR str,
  [in]            LPCWSTR  pszAssoc,
  [in, optional]  LPCWSTR  pszExtra,
  [out, optional] LPWSTR   pszOut,
  [in, out]       DWORD    *pcchOut
);