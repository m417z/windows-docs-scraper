typedef struct _WTS_PROCESS_INFOW {
  DWORD  SessionId;
  DWORD  ProcessId;
  LPWSTR pProcessName;
  PSID   pUserSid;
} WTS_PROCESS_INFOW, *PWTS_PROCESS_INFOW;