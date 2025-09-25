typedef struct CF_PROCESS_INFO {
  DWORD  StructSize;
  DWORD  ProcessId;
  PCWSTR ImagePath;
  PCWSTR PackageName;
  PCWSTR ApplicationId;
  PCWSTR CommandLine;
  DWORD  SessionId;
} CF_PROCESS_INFO;