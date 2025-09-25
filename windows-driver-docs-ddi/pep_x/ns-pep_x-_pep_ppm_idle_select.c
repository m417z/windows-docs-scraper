typedef struct _PEP_PPM_IDLE_SELECT {
  [in]  PPEP_PROCESSOR_IDLE_CONSTRAINTS Constraints;
  [out] BOOLEAN                         AbortTransition;
  [out] ULONG                           IdleStateIndex;
  [out] ULONG                           DependencyArrayUsed;
  [in]  ULONG                           DependencyArrayCount;
  [in]  PPEP_PROCESSOR_IDLE_DEPENDENCY  DependencyArray;
  [out] ULONG                           PlatformIdleStateIndex;
} PEP_PPM_IDLE_SELECT, *PPEP_PPM_IDLE_SELECT;