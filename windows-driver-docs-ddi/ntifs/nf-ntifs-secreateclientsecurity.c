NTSTATUS SeCreateClientSecurity(
  [in]  PETHREAD                     ClientThread,
  [in]  PSECURITY_QUALITY_OF_SERVICE ClientSecurityQos,
        BOOLEAN                      RemoteSession,
  [out] PSECURITY_CLIENT_CONTEXT     ClientContext
);