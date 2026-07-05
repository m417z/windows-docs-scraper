typedef union _D3DKMT_PROCESS_VERIFIER_VIDMM_FLAGS {
  struct {
    UINT ForceSynchronousEvict : 1;
    UINT NeverDeferEvictions : 1;
    UINT AlwaysFailCommitOnReclaim : 1;
    UINT AlwaysPlaceInDemotedLocation : 1;
    UINT IgnoreBudgetCap : 1;
    UINT AlwaysCreateLocalAlloc : 1;
    UINT DisablePermanentUmVaUpgrade : 1;
    UINT AlwaysUseSystemHeap : 1;
    UINT SynchronousDeferredCommands : 1;
    UINT Reserved : 23;
  };
  UINT32 Value;
} D3DKMT_PROCESS_VERIFIER_VIDMM_FLAGS;