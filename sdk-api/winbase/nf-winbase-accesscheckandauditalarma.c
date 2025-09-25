BOOL AccessCheckAndAuditAlarmA(
  [in]           LPCSTR               SubsystemName,
  [in, optional] LPVOID               HandleId,
  [in]           LPSTR                ObjectTypeName,
  [in, optional] LPSTR                ObjectName,
  [in]           PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]           DWORD                DesiredAccess,
  [in]           PGENERIC_MAPPING     GenericMapping,
  [in]           BOOL                 ObjectCreation,
  [out]          LPDWORD              GrantedAccess,
  [out]          LPBOOL               AccessStatus,
  [out]          LPBOOL               pfGenerateOnClose
);