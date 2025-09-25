NTSTATUS FwpmCalloutGetSecurityInfoByKey0(
  [in]           HANDLE               engineHandle,
  [in, optional] const GUID           *key,
  [in]           SECURITY_INFORMATION securityInfo,
  [out]          PSID                 *sidOwner,
  [out]          PSID                 *sidGroup,
  [out]          PACL                 *dacl,
  [out]          PACL                 *sacl,
  [out]          PSECURITY_DESCRIPTOR *securityDescriptor
);