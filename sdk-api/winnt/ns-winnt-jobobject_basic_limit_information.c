typedef struct _JOBOBJECT_BASIC_LIMIT_INFORMATION {
  LARGE_INTEGER PerProcessUserTimeLimit;
  LARGE_INTEGER PerJobUserTimeLimit;
  DWORD         LimitFlags;
  SIZE_T        MinimumWorkingSetSize;
  SIZE_T        MaximumWorkingSetSize;
  DWORD         ActiveProcessLimit;
  ULONG_PTR     Affinity;
  DWORD         PriorityClass;
  DWORD         SchedulingClass;
} JOBOBJECT_BASIC_LIMIT_INFORMATION, *PJOBOBJECT_BASIC_LIMIT_INFORMATION;