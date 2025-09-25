BOOL GetSecurityDescriptorSacl(
  [in]  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [out] LPBOOL               lpbSaclPresent,
  [out] PACL                 *pSacl,
  [out] LPBOOL               lpbSaclDefaulted
);