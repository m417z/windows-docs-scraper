BOOL SetSecurityDescriptorOwner(
  [in, out]      PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in, optional] PSID                 pOwner,
  [in]           BOOL                 bOwnerDefaulted
);