BOOL SetAclInformation(
  [in, out] PACL                  pAcl,
  [in]      LPVOID                pAclInformation,
  [in]      DWORD                 nAclInformationLength,
  [in]      ACL_INFORMATION_CLASS dwAclInformationClass
);