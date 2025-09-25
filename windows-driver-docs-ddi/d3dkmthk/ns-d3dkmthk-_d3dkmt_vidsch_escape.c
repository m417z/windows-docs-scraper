typedef struct _D3DKMT_VIDSCH_ESCAPE {
  D3DKMT_VIDSCHESCAPETYPE            Type;
  union {
    BOOL                              PreemptionControl;
    BOOL                              EnableContextDelay;
    struct {
      ULONG TdrControl;
      union {
        ULONG NodeOrdinal;
      };
    } TdrControl2;
    BOOL                              SuspendScheduler;
    ULONG                             TdrControl;
    ULONG                             SuspendTime;
    struct {
      UINT Count;
      UINT Time;
    } TdrLimit;
    D3DKMT_ESCAPE_PFN_CONTROL_COMMAND PfnControl;
  };
  D3DKMT_ESCAPE_VIRTUAL_REFRESH_RATE VirtualRefreshRateControl;
} D3DKMT_VIDSCH_ESCAPE;