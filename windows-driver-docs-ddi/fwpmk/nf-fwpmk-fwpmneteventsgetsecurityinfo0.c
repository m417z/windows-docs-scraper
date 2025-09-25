NTSTATUS FwpmNetEventsGetSecurityInfo0(
  [in]            HANDLE               engineHandle,
  [in]            SECURITY_INFORMATION securityInfo,
  [out, optional] PSID                 *sidOwner,
  [out, optional] PSID                 *sidGroup,
  [out, optional] PACL                 *dacl,
  [out]           PACL                 *sacl,
  [out, optional] PSECURITY_DESCRIPTOR *securityDescriptor
);