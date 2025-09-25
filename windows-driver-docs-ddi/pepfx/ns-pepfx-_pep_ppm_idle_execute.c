typedef struct _PEP_PPM_IDLE_EXECUTE {
  [out] NTSTATUS Status;
  [in]  ULONG    ProcessorState;
  [in]  ULONG    PlatformState;
} PEP_PPM_IDLE_EXECUTE, *PPEP_PPM_IDLE_EXECUTE;