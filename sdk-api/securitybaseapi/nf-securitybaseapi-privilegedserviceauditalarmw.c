BOOL PrivilegedServiceAuditAlarmW(
  [in] LPCWSTR        SubsystemName,
  [in] LPCWSTR        ServiceName,
  [in] HANDLE         ClientToken,
  [in] PPRIVILEGE_SET Privileges,
  [in] BOOL           AccessGranted
);