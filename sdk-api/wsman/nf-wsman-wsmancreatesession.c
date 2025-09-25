DWORD WSManCreateSession(
  [in]           WSMAN_API_HANDLE                 apiHandle,
  [in, optional] PCWSTR                           connection,
                 DWORD                            flags,
  [in, optional] WSMAN_AUTHENTICATION_CREDENTIALS *serverAuthenticationCredentials,
  [in, optional] WSMAN_PROXY_INFO                 *proxyInfo,
  [out]          WSMAN_SESSION_HANDLE             *session
);