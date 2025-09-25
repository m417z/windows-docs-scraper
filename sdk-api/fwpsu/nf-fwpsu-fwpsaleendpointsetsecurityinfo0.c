DWORD FwpsAleEndpointSetSecurityInfo0(
  HANDLE               engineHandle,
  SECURITY_INFORMATION securityInfo,
  const SID            *sidOwner,
  const SID            *sidGroup,
  const ACL            *dacl,
  const ACL            *sacl
);