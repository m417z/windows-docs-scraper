AUTHZAPI BOOL AuthzAccessCheck(
  [in]            DWORD                              Flags,
  [in]            AUTHZ_CLIENT_CONTEXT_HANDLE        hAuthzClientContext,
  [in]            PAUTHZ_ACCESS_REQUEST              pRequest,
  [in, optional]  AUTHZ_AUDIT_EVENT_HANDLE           hAuditEvent,
  [in]            PSECURITY_DESCRIPTOR               pSecurityDescriptor,
  [in, optional]  PSECURITY_DESCRIPTOR               *OptionalSecurityDescriptorArray,
  [in, optional]  DWORD                              OptionalSecurityDescriptorCount,
  [in, out]       PAUTHZ_ACCESS_REPLY                pReply,
  [out, optional] PAUTHZ_ACCESS_CHECK_RESULTS_HANDLE phAccessCheckResults
);