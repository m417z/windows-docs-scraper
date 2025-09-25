AUTHZAPI BOOL AuthzCachedAccessCheck(
  [in]  DWORD                             Flags,
  [in]  AUTHZ_ACCESS_CHECK_RESULTS_HANDLE hAccessCheckResults,
  [in]  PAUTHZ_ACCESS_REQUEST             pRequest,
  [in]  AUTHZ_AUDIT_EVENT_HANDLE          hAuditEvent,
  [out] PAUTHZ_ACCESS_REPLY               pReply
);