typedef struct _JOBOBJECT_EXTENDED_LIMIT_INFORMATION {
  JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
  IO_COUNTERS                       IoInfo;
  SIZE_T                            ProcessMemoryLimit;
  SIZE_T                            JobMemoryLimit;
  SIZE_T                            PeakProcessMemoryUsed;
  SIZE_T                            PeakJobMemoryUsed;
} JOBOBJECT_EXTENDED_LIMIT_INFORMATION, *PJOBOBJECT_EXTENDED_LIMIT_INFORMATION;