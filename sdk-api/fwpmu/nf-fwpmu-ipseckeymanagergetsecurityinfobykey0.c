DWORD IPsecKeyManagerGetSecurityInfoByKey0(
  [in]            HANDLE               engineHandle,
                  const void           *reserved,
  [in]            SECURITY_INFORMATION securityInfo,
  [out, optional] PSID                 *sidOwner,
  [out, optional] PSID                 *sidGroup,
  [out, optional] PACL                 *dacl,
  [out, optional] PACL                 *sacl,
  [out]           PSECURITY_DESCRIPTOR *securityDescriptor
);