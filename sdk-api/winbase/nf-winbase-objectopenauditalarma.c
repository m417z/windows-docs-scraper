BOOL ObjectOpenAuditAlarmA(
  [in]           LPCSTR               SubsystemName,
  [in]           LPVOID               HandleId,
  [in]           LPSTR                ObjectTypeName,
  [in, optional] LPSTR                ObjectName,
  [in]           PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]           HANDLE               ClientToken,
  [in]           DWORD                DesiredAccess,
  [in]           DWORD                GrantedAccess,
  [in, optional] PPRIVILEGE_SET       Privileges,
  [in]           BOOL                 ObjectCreation,
  [in]           BOOL                 AccessGranted,
  [out]          LPBOOL               GenerateOnClose
);