typedef struct _PEP_PPM_IDLE_EXECUTE_V2 {
  [out] NTSTATUS Status;
  [in]  ULONG    ProcessorState;
  [in]  ULONG    PlatformState;
        ULONG    CoordinatedStateCount;
        PULONG   CoordinatedStates;
} PEP_PPM_IDLE_EXECUTE_V2, *PPEP_PPM_IDLE_EXECUTE_V2;