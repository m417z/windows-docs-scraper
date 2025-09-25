typedef struct _DXGKARG_PREEMPTCOMMAND {
  [in] UINT                     PreemptionFenceId;
  [in] UINT                     NodeOrdinal;
  [in] UINT                     EngineOrdinal;
  [in] DXGK_PREEMPTCOMMANDFLAGS Flags;
} DXGKARG_PREEMPTCOMMAND;