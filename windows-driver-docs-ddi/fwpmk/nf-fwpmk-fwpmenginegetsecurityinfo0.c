NTSTATUS FwpmEngineGetSecurityInfo0(
  [in]  HANDLE               engineHandle,
  [in]  SECURITY_INFORMATION securityInfo,
  [out] PSID                 *sidOwner,
  [out] PSID                 *sidGroup,
  [out] PACL                 *dacl,
  [out] PACL                 *sacl,
  [out] PSECURITY_DESCRIPTOR *securityDescriptor
);