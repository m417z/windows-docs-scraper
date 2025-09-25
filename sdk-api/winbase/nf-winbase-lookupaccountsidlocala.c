BOOL LookupAccountSidLocalA(
  [in]            PSID          Sid,
  [out, optional] LPSTR         Name,
  [in, out]       LPDWORD       cchName,
  [out, optional] LPSTR         ReferencedDomainName,
  [in, out]       LPDWORD       cchReferencedDomainName,
  [out]           PSID_NAME_USE peUse
);