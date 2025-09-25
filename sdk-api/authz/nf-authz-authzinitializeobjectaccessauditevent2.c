AUTHZAPI BOOL AuthzInitializeObjectAccessAuditEvent2(
  [in]  DWORD                         Flags,
  [in]  AUTHZ_AUDIT_EVENT_TYPE_HANDLE hAuditEventType,
  [in]  PWSTR                         szOperationType,
  [in]  PWSTR                         szObjectType,
  [in]  PWSTR                         szObjectName,
  [in]  PWSTR                         szAdditionalInfo,
  [in]  PWSTR                         szAdditionalInfo2,
  [out] PAUTHZ_AUDIT_EVENT_HANDLE     phAuditEvent,
  [in]  DWORD                         dwAdditionalParameterCount,
        ...                           
);