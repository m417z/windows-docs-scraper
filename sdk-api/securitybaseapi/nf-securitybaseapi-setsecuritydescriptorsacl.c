BOOL SetSecurityDescriptorSacl(
  [in, out]      PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]           BOOL                 bSaclPresent,
  [in, optional] PACL                 pSacl,
  [in]           BOOL                 bSaclDefaulted
);