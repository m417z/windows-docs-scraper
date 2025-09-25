AUTHZAPI BOOL AuthzInitializeObjectAccessAuditEvent(
  [in]  DWORD                         Flags,
  [in]  AUTHZ_AUDIT_EVENT_TYPE_HANDLE hAuditEventType,
  [in]  PWSTR                         szOperationType,
  [in]  PWSTR                         szObjectType,
  [in]  PWSTR                         szObjectName,
  [in]  PWSTR                         szAdditionalInfo,
  [out] PAUTHZ_AUDIT_EVENT_HANDLE     phAuditEvent,
  [in]  DWORD                         dwAdditionalParameterCount,
        ...                           
);