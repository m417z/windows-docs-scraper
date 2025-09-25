BOOL ObjectPrivilegeAuditAlarmA(
  [in] LPCSTR         SubsystemName,
  [in] LPVOID         HandleId,
  [in] HANDLE         ClientToken,
  [in] DWORD          DesiredAccess,
  [in] PPRIVILEGE_SET Privileges,
  [in] BOOL           AccessGranted
);