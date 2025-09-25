typedef struct _JOBOBJECT_LIMIT_VIOLATION_INFORMATION {
  DWORD                            LimitFlags;
  DWORD                            ViolationLimitFlags;
  DWORD64                          IoReadBytes;
  DWORD64                          IoReadBytesLimit;
  DWORD64                          IoWriteBytes;
  DWORD64                          IoWriteBytesLimit;
  LARGE_INTEGER                    PerJobUserTime;
  LARGE_INTEGER                    PerJobUserTimeLimit;
  DWORD64                          JobMemory;
  DWORD64                          JobMemoryLimit;
  JOBOBJECT_RATE_CONTROL_TOLERANCE RateControlTolerance;
  JOBOBJECT_RATE_CONTROL_TOLERANCE RateControlToleranceLimit;
} JOBOBJECT_LIMIT_VIOLATION_INFORMATION, *PJOBOBJECT_LIMIT_VIOLATION_INFORMATION;