typedef struct _PEP_PROCESSOR_IDLE_STATE {
  union {
    ULONG Ulong;
    struct {
      ULONG Interruptible : 1;
      ULONG CacheCoherent : 1;
      ULONG ThreadContextRetained : 1;
      ULONG CStateType : 4;
      ULONG Reserved : 25;
    };
  };
} PEP_PROCESSOR_IDLE_STATE, *PPEP_PROCESSOR_IDLE_STATE;