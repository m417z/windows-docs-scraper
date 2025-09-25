DWORD SetSecurityInfo(
  [in]           HANDLE               handle,
  [in]           SE_OBJECT_TYPE       ObjectType,
  [in]           SECURITY_INFORMATION SecurityInfo,
  [in, optional] PSID                 psidOwner,
  [in, optional] PSID                 psidGroup,
  [in, optional] PACL                 pDacl,
  [in, optional] PACL                 pSacl
);