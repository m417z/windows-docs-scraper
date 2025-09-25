typedef struct _TRACE_LOGFILE_HEADER {
  ULONG                     BufferSize;
  union {
    ULONG Version;
    struct {
      UCHAR MajorVersion;
      UCHAR MinorVersion;
      UCHAR SubVersion;
      UCHAR SubMinorVersion;
    } VersionDetail;
  } DUMMYUNIONNAME;
  ULONG                     ProviderVersion;
  ULONG                     NumberOfProcessors;
  LARGE_INTEGER             EndTime;
  ULONG                     TimerResolution;
  ULONG                     MaximumFileSize;
  ULONG                     LogFileMode;
  ULONG                     BuffersWritten;
  union {
    GUID LogInstanceGuid;
    struct {
      ULONG StartBuffers;
      ULONG PointerSize;
      ULONG EventsLost;
      ULONG CpuSpeedInMHz;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME2;
#if ...
  PWCHAR                    LoggerName;
#if ...
  PWCHAR                    LogFileName;
#if ...
  RTL_TIME_ZONE_INFORMATION TimeZone;
#else
  LPWSTR                    LoggerName;
#endif
#else
  LPWSTR                    LogFileName;
#endif
#else
  TIME_ZONE_INFORMATION     TimeZone;
#endif
  LARGE_INTEGER             BootTime;
  LARGE_INTEGER             PerfFreq;
  LARGE_INTEGER             StartTime;
  ULONG                     ReservedFlags;
  ULONG                     BuffersLost;
} TRACE_LOGFILE_HEADER, *PTRACE_LOGFILE_HEADER;