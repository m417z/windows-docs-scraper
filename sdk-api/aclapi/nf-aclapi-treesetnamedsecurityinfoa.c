DWORD TreeSetNamedSecurityInfoA(
  [in]           LPSTR                pObjectName,
  [in]           SE_OBJECT_TYPE       ObjectType,
  [in]           SECURITY_INFORMATION SecurityInfo,
  [in, optional] PSID                 pOwner,
  [in, optional] PSID                 pGroup,
  [in, optional] PACL                 pDacl,
  [in, optional] PACL                 pSacl,
  [in]           DWORD                dwAction,
  [in]           FN_PROGRESS          fnProgress,
  [in]           PROG_INVOKE_SETTING  ProgressInvokeSetting,
  [in, optional] PVOID                Args
);