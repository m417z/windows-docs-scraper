NTSTATUS FwpmProviderContextGetSecurityInfoByKey0(
  [in]            HANDLE               engineHandle,
  [in, optional]  const GUID           *key,
  [in]            SECURITY_INFORMATION securityInfo,
  [out, optional] PSID                 *sidOwner,
  [out, optional] PSID                 *sidGroup,
  [out, optional] PACL                 *dacl,
  [out, optional] PACL                 *sacl,
  [out]           PSECURITY_DESCRIPTOR *securityDescriptor
);