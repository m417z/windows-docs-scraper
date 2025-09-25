BOOL GetSecurityDescriptorOwner(
  [in]  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [out] PSID                 *pOwner,
  [out] LPBOOL               lpbOwnerDefaulted
);