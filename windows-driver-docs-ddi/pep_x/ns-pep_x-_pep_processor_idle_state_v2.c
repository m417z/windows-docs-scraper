typedef struct _PEP_PROCESSOR_IDLE_STATE_V2 {
  union {
    ULONG Ulong;
    struct {
      ULONG Interruptible : 1;
      ULONG CacheCoherent : 1;
      ULONG ThreadContextRetained : 1;
      ULONG CStateType : 4;
      ULONG WakesSpuriously : 1;
      ULONG PlatformOnly : 1;
      ULONG Autonomous : 1;
      ULONG Reserved : 22;
    };
  };
  ULONG Latency;
  ULONG BreakEvenDuration;
} PEP_PROCESSOR_IDLE_STATE_V2, *PPEP_PROCESSOR_IDLE_STATE_V2;