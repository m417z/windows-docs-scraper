AUTHZAPI BOOL AuthzEnumerateSecurityEventSources(
  [in]      DWORD                             dwFlags,
  [out]     PAUTHZ_SOURCE_SCHEMA_REGISTRATION Buffer,
  [out]     PDWORD                            pdwCount,
  [in, out] PDWORD                            pdwLength
);