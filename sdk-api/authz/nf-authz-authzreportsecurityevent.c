AUTHZAPI BOOL AuthzReportSecurityEvent(
  [in]           DWORD                                dwFlags,
  [in, out]      AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE hEventProvider,
  [in]           DWORD                                dwAuditId,
  [in, optional] PSID                                 pUserSid,
  [in]           DWORD                                dwCount,
                 ...                                  
);