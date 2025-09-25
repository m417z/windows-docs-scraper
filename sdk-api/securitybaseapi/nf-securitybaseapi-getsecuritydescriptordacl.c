BOOL GetSecurityDescriptorDacl(
  [in]  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [out] LPBOOL               lpbDaclPresent,
  [out] PACL                 *pDacl,
  [out] LPBOOL               lpbDaclDefaulted
);