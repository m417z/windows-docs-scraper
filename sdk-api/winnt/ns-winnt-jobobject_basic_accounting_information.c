typedef struct _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
  LARGE_INTEGER TotalUserTime;
  LARGE_INTEGER TotalKernelTime;
  LARGE_INTEGER ThisPeriodTotalUserTime;
  LARGE_INTEGER ThisPeriodTotalKernelTime;
  DWORD         TotalPageFaultCount;
  DWORD         TotalProcesses;
  DWORD         ActiveProcesses;
  DWORD         TotalTerminatedProcesses;
} JOBOBJECT_BASIC_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;