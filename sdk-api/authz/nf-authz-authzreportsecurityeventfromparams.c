AUTHZAPI BOOL AuthzReportSecurityEventFromParams(
  [in]           DWORD                                dwFlags,
  [in]           AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE hEventProvider,
  [in]           DWORD                                dwAuditId,
  [in, optional] PSID                                 pUserSid,
  [in]           PAUDIT_PARAMS                        pParams
);