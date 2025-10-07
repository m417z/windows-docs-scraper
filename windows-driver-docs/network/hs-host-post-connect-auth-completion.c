typedef DWORD (WINAPI *HS_HOST_POST_CONNECT_AUTH_COMPLETION)(
  _In_     HANDLE                    hPluginContext,
  _In_     DWORD                     dwConnectionId,
  _In_     eHS_AUTHENTICATION_RESULT AuthResult,
  _In_opt_ LPVOID                    pvReserved
);