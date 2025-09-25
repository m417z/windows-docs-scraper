typedef struct _WTS_PROCESS_INFOA {
  DWORD SessionId;
  DWORD ProcessId;
  LPSTR pProcessName;
  PSID  pUserSid;
} WTS_PROCESS_INFOA, *PWTS_PROCESS_INFOA;