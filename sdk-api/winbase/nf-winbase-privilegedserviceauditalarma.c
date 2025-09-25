BOOL PrivilegedServiceAuditAlarmA(
  [in] LPCSTR         SubsystemName,
  [in] LPCSTR         ServiceName,
  [in] HANDLE         ClientToken,
  [in] PPRIVILEGE_SET Privileges,
  [in] BOOL           AccessGranted
);