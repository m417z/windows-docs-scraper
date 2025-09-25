typedef struct _PERF_OBJECT_TYPE {
  DWORD         TotalByteLength;
  DWORD         DefinitionLength;
  DWORD         HeaderLength;
  DWORD         ObjectNameTitleIndex;
#if ...
  DWORD         ObjectNameTitle;
#else
  LPWSTR        ObjectNameTitle;
#endif
  DWORD         ObjectHelpTitleIndex;
#if ...
  DWORD         ObjectHelpTitle;
#else
  LPWSTR        ObjectHelpTitle;
#endif
  DWORD         DetailLevel;
  DWORD         NumCounters;
  LONG          DefaultCounter;
  LONG          NumInstances;
  DWORD         CodePage;
  LARGE_INTEGER PerfTime;
  LARGE_INTEGER PerfFreq;
} PERF_OBJECT_TYPE, *PPERF_OBJECT_TYPE;