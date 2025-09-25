BOOL AccessCheckByTypeAndAuditAlarmA(
  [in]                LPCSTR               SubsystemName,
  [in]                LPVOID               HandleId,
  [in]                LPCSTR               ObjectTypeName,
  [in, optional]      LPCSTR               ObjectName,
  [in]                PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in, optional]      PSID                 PrincipalSelfSid,
  [in]                DWORD                DesiredAccess,
  [in]                AUDIT_EVENT_TYPE     AuditType,
  [in]                DWORD                Flags,
  [in, out, optional] POBJECT_TYPE_LIST    ObjectTypeList,
  [in]                DWORD                ObjectTypeListLength,
  [in]                PGENERIC_MAPPING     GenericMapping,
  [in]                BOOL                 ObjectCreation,
  [out]               LPDWORD              GrantedAccess,
  [out]               LPBOOL               AccessStatus,
  [out]               LPBOOL               pfGenerateOnClose
);