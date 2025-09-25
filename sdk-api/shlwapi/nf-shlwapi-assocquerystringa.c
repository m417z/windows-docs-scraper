LWSTDAPI AssocQueryStringA(
  [in]            ASSOCF   flags,
  [in]            ASSOCSTR str,
  [in]            LPCSTR   pszAssoc,
  [in, optional]  LPCSTR   pszExtra,
  [out, optional] LPSTR    pszOut,
  [in, out]       DWORD    *pcchOut
);