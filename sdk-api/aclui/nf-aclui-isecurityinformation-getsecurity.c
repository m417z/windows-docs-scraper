HRESULT GetSecurity(
  [in]  SECURITY_INFORMATION RequestedInformation,
  [out] PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
  [in]  BOOL                 fDefault
);