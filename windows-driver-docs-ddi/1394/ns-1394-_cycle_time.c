typedef struct _CYCLE_TIME {
  ULONG CL_CycleOffset : 12;
  ULONG CL_CycleCount : 13;
  ULONG CL_SecondCount : 7;
} CYCLE_TIME, *PCYCLE_TIME;