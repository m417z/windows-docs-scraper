BOOL LookupAccountNameA(
  [in, optional]  LPCSTR        lpSystemName,
  [in]            LPCSTR        lpAccountName,
  [out, optional] PSID          Sid,
  [in, out]       LPDWORD       cbSid,
  [out, optional] LPSTR         ReferencedDomainName,
  [in, out]       LPDWORD       cchReferencedDomainName,
  [out]           PSID_NAME_USE peUse
);