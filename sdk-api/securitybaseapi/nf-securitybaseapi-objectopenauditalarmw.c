BOOL ObjectOpenAuditAlarmW(
  [in]           LPCWSTR              SubsystemName,
  [in]           LPVOID               HandleId,
  [in]           LPWSTR               ObjectTypeName,
  [in, optional] LPWSTR               ObjectName,
  [in]           PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]           HANDLE               ClientToken,
  [in]           DWORD                DesiredAccess,
  [in]           DWORD                GrantedAccess,
  [in, optional] PPRIVILEGE_SET       Privileges,
  [in]           BOOL                 ObjectCreation,
  [in]           BOOL                 AccessGranted,
  [out]          LPBOOL               GenerateOnClose
);