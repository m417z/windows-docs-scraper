AUTHZAPI BOOL AuthzOpenObjectAudit(
  [in] DWORD                       Flags,
  [in] AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext,
  [in] PAUTHZ_ACCESS_REQUEST       pRequest,
  [in] AUTHZ_AUDIT_EVENT_HANDLE    hAuditEvent,
  [in] PSECURITY_DESCRIPTOR        pSecurityDescriptor,
  [in] PSECURITY_DESCRIPTOR        *OptionalSecurityDescriptorArray,
  [in] DWORD                       OptionalSecurityDescriptorCount,
  [in] PAUTHZ_ACCESS_REPLY         pReply
);