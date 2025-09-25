DWORD GetNamedSecurityInfoW(
  [in]            LPCWSTR              pObjectName,
  [in]            SE_OBJECT_TYPE       ObjectType,
  [in]            SECURITY_INFORMATION SecurityInfo,
  [out, optional] PSID                 *ppsidOwner,
  [out, optional] PSID                 *ppsidGroup,
  [out, optional] PACL                 *ppDacl,
  [out, optional] PACL                 *ppSacl,
  [out, optional] PSECURITY_DESCRIPTOR *ppSecurityDescriptor
);