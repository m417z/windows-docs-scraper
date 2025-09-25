BOOL GetSecurityDescriptorGroup(
  [in]  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [out] PSID                 *pGroup,
  [out] LPBOOL               lpbGroupDefaulted
);