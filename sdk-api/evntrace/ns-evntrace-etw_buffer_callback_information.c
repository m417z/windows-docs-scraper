typedef struct ETW_BUFFER_CALLBACK_INFORMATION {
  PROCESSTRACE_HANDLE        TraceHandle;
  const TRACE_LOGFILE_HEADER *LogfileHeader;
  ULONG                      BuffersRead;
} ETW_BUFFER_CALLBACK_INFORMATION;