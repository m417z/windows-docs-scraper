typedef struct _PEP_PPM_IDLE_COMPLETE_V2 {
  [in] ULONG  ProcessorState;
  [in] ULONG  PlatformState;
       ULONG  CoordinatedStateCount;
       PULONG CoordinatedStates;
} PEP_PPM_IDLE_COMPLETE_V2, *PPEP_PPM_IDLE_COMPLETE_V2;