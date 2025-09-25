AUTHZAPI BOOL AuthzSetAppContainerInformation(
  [in]           AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext,
  [in]           PSID                        pAppContainerSid,
  [in]           DWORD                       CapabilityCount,
  [in, optional] PSID_AND_ATTRIBUTES         pCapabilitySids
);