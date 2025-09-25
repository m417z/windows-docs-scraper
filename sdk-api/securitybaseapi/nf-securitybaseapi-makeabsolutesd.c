BOOL MakeAbsoluteSD(
  [in]            PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
  [out, optional] PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
  [in, out]       LPDWORD              lpdwAbsoluteSecurityDescriptorSize,
  [out, optional] PACL                 pDacl,
  [in, out]       LPDWORD              lpdwDaclSize,
  [out, optional] PACL                 pSacl,
  [in, out]       LPDWORD              lpdwSaclSize,
  [out, optional] PSID                 pOwner,
  [in, out]       LPDWORD              lpdwOwnerSize,
  [out, optional] PSID                 pPrimaryGroup,
  [in, out]       LPDWORD              lpdwPrimaryGroupSize
);