LWSTDAPI AssocQueryStringByKeyA(
  [in]            ASSOCF   flags,
  [in]            ASSOCSTR str,
  [in]            HKEY     hkAssoc,
  [in, optional]  LPCSTR   pszExtra,
  [out, optional] LPSTR    pszOut,
  [in, out]       DWORD    *pcchOut
);