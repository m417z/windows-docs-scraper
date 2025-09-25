typedef union _D3DKMT_PROCESS_VERIFIER_VIDMM_FLAGS {
  struct {
    UINT ForceSynchronousEvict : 1;
    UINT NeverDeferEvictions : 1;
    UINT AlwaysFailCommitOnReclaim : 1;
    UINT AlwaysPlaceInDemotedLocation : 1;
    UINT IgnoreBudgetCap : 1;
    UINT Reserved : 27;
  };
  UINT32 Value;
} D3DKMT_PROCESS_VERIFIER_VIDMM_FLAGS;