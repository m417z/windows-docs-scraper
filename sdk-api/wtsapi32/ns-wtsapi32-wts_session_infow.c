typedef struct _WTS_SESSION_INFOW {
  DWORD                  SessionId;
  LPWSTR                 pWinStationName;
  WTS_CONNECTSTATE_CLASS State;
} WTS_SESSION_INFOW, *PWTS_SESSION_INFOW;