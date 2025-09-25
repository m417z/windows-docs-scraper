typedef struct _WTS_SESSION_INFO_1A {
  DWORD                  ExecEnvId;
  WTS_CONNECTSTATE_CLASS State;
  DWORD                  SessionId;
  LPSTR                  pSessionName;
  LPSTR                  pHostName;
  LPSTR                  pUserName;
  LPSTR                  pDomainName;
  LPSTR                  pFarmName;
} WTS_SESSION_INFO_1A, *PWTS_SESSION_INFO_1A;