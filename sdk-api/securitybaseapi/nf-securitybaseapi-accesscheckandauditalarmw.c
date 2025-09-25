BOOL AccessCheckAndAuditAlarmW(
  [in]           LPCWSTR              SubsystemName,
  [in, optional] LPVOID               HandleId,
  [in]           LPWSTR               ObjectTypeName,
  [in, optional] LPWSTR               ObjectName,
  [in]           PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]           DWORD                DesiredAccess,
  [in]           PGENERIC_MAPPING     GenericMapping,
  [in]           BOOL                 ObjectCreation,
  [out]          LPDWORD              GrantedAccess,
  [out]          LPBOOL               AccessStatus,
  [out]          LPBOOL               pfGenerateOnClose
);