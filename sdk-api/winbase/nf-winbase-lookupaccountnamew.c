BOOL LookupAccountNameW(
  [in, optional]  LPCWSTR       lpSystemName,
  [in]            LPCWSTR       lpAccountName,
  [out, optional] PSID          Sid,
  [in, out]       LPDWORD       cbSid,
  [out, optional] LPWSTR        ReferencedDomainName,
  [in, out]       LPDWORD       cchReferencedDomainName,
  [out]           PSID_NAME_USE peUse
);