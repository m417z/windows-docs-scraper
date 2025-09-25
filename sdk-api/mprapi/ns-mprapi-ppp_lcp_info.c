typedef struct _PPP_LCP_INFO {
  DWORD dwError;
  DWORD dwAuthenticationProtocol;
  DWORD dwAuthenticationData;
  DWORD dwRemoteAuthenticationProtocol;
  DWORD dwRemoteAuthenticationData;
  DWORD dwTerminateReason;
  DWORD dwRemoteTerminateReason;
  DWORD dwOptions;
  DWORD dwRemoteOptions;
  DWORD dwEapTypeId;
  DWORD dwRemoteEapTypeId;
} PPP_LCP_INFO;