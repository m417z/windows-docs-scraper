typedef struct _SYSTEM_CPU_SET_INFORMATION {
  DWORD                    Size;
  CPU_SET_INFORMATION_TYPE Type;
  union {
    struct {
      DWORD   Id;
      WORD    Group;
      BYTE    LogicalProcessorIndex;
      BYTE    CoreIndex;
      BYTE    LastLevelCacheIndex;
      BYTE    NumaNodeIndex;
      BYTE    EfficiencyClass;
      union {
        BYTE AllFlags;
        struct {
          BYTE Parked : 1;
          BYTE Allocated : 1;
          BYTE AllocatedToTargetProcess : 1;
          BYTE RealTime : 1;
          BYTE ReservedFlags : 4;
        } DUMMYSTRUCTNAME;
      } DUMMYUNIONNAME2;
      union {
        DWORD Reserved;
        BYTE  SchedulingClass;
      };
      DWORD64 AllocationTag;
    } CpuSet;
  } DUMMYUNIONNAME;
} SYSTEM_CPU_SET_INFORMATION, *PSYSTEM_CPU_SET_INFORMATION;