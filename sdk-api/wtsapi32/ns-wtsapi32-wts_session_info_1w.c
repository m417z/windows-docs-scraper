typedef struct _WTS_SESSION_INFO_1W {
  DWORD                  ExecEnvId;
  WTS_CONNECTSTATE_CLASS State;
  DWORD                  SessionId;
  LPWSTR                 pSessionName;
  LPWSTR                 pHostName;
  LPWSTR                 pUserName;
  LPWSTR                 pDomainName;
  LPWSTR                 pFarmName;
} WTS_SESSION_INFO_1W, *PWTS_SESSION_INFO_1W;