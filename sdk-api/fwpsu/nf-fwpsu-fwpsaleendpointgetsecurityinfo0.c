DWORD FwpsAleEndpointGetSecurityInfo0(
  HANDLE               engineHandle,
  SECURITY_INFORMATION securityInfo,
  PSID                 *sidOwner,
  PSID                 *sidGroup,
  PACL                 *dacl,
  PACL                 *sacl,
  PSECURITY_DESCRIPTOR *securityDescriptor
);