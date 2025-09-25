BOOL SetSecurityDescriptorDacl(
  [in, out]      PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]           BOOL                 bDaclPresent,
  [in, optional] PACL                 pDacl,
  [in]           BOOL                 bDaclDefaulted
);