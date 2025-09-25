BOOL SetSecurityDescriptorGroup(
  [in, out]      PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in, optional] PSID                 pGroup,
  [in]           BOOL                 bGroupDefaulted
);