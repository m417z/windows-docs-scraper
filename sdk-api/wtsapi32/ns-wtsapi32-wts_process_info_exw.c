typedef struct _WTS_PROCESS_INFO_EXW {
  DWORD         SessionId;
  DWORD         ProcessId;
  LPWSTR        pProcessName;
  PSID          pUserSid;
  DWORD         NumberOfThreads;
  DWORD         HandleCount;
  DWORD         PagefileUsage;
  DWORD         PeakPagefileUsage;
  DWORD         WorkingSetSize;
  DWORD         PeakWorkingSetSize;
  LARGE_INTEGER UserTime;
  LARGE_INTEGER KernelTime;
} WTS_PROCESS_INFO_EXW, *PWTS_PROCESS_INFO_EXW;