ETW_APP_DECLSPEC_DEPRECATED PROCESSTRACE_HANDLE WMIAPI OpenTraceFromRealTimeLoggerWithAllocationOptions(
  PCWSTR                       LoggerName,
  const ETW_OPEN_TRACE_OPTIONS *Options,
  ULONG_PTR                    AllocationSize,
  HANDLE                       MemoryPartitionHandle,
  TRACE_LOGFILE_HEADER         *LogFileHeader
);