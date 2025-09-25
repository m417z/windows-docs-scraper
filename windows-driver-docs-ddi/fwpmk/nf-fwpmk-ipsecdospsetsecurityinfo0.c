NTSTATUS IPsecDospSetSecurityInfo0(
  [in]           HANDLE               engineHandle,
  [in]           SECURITY_INFORMATION securityInfo,
  [in, optional] const SID            *sidOwner,
  [in, optional] const SID            *sidGroup,
  [in, optional] const ACL            *dacl,
  [in, optional] const ACL            *sacl
);