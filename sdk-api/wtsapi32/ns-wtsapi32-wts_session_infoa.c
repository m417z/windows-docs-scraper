typedef struct _WTS_SESSION_INFOA {
  DWORD                  SessionId;
  LPSTR                  pWinStationName;
  WTS_CONNECTSTATE_CLASS State;
} WTS_SESSION_INFOA, *PWTS_SESSION_INFOA;