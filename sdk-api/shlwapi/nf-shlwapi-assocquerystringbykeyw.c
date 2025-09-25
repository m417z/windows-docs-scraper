LWSTDAPI AssocQueryStringByKeyW(
  [in]            ASSOCF   flags,
  [in]            ASSOCSTR str,
  [in]            HKEY     hkAssoc,
  [in, optional]  LPCWSTR  pszExtra,
  [out, optional] LPWSTR   pszOut,
  [in, out]       DWORD    *pcchOut
);