NTSTATUS FwpmLayerSetSecurityInfoByKey0(
  [in] HANDLE               engineHandle,
       const GUID           *key,
       SECURITY_INFORMATION securityInfo,
       const SID            *sidOwner,
       const SID            *sidGroup,
       const ACL            *dacl,
       const ACL            *sacl
);