BOOL AccessCheckByTypeResultListAndAuditAlarmByHandleW(
  [in]                LPCWSTR              SubsystemName,
  [in]                LPVOID               HandleId,
  [in]                HANDLE               ClientToken,
  [in]                LPCWSTR              ObjectTypeName,
  [in, optional]      LPCWSTR              ObjectName,
  [in]                PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in, optional]      PSID                 PrincipalSelfSid,
  [in]                DWORD                DesiredAccess,
  [in]                AUDIT_EVENT_TYPE     AuditType,
  [in]                DWORD                Flags,
  [in, out, optional] POBJECT_TYPE_LIST    ObjectTypeList,
  [in]                DWORD                ObjectTypeListLength,
  [in]                PGENERIC_MAPPING     GenericMapping,
  [in]                BOOL                 ObjectCreation,
                      LPDWORD              GrantedAccessList,
  [out]               LPDWORD              AccessStatusList,
  [out]               LPBOOL               pfGenerateOnClose
);