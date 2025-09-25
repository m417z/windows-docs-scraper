BOOL LookupAccountSidLocalW(
  [in]            PSID          Sid,
  [out, optional] LPWSTR        Name,
  [in, out]       LPDWORD       cchName,
  [out, optional] LPWSTR        ReferencedDomainName,
  [in, out]       LPDWORD       cchReferencedDomainName,
  [out]           PSID_NAME_USE peUse
);