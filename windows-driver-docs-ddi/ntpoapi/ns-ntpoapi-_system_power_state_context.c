typedef struct _SYSTEM_POWER_STATE_CONTEXT {
  union {
    struct {
      ULONG Reserved1 : 8;
      ULONG TargetSystemState : 4;
      ULONG EffectiveSystemState : 4;
      ULONG CurrentSystemState : 4;
      ULONG IgnoreHibernationPath : 1;
      ULONG PseudoTransition : 1;
      ULONG KernelSoftReboot : 1;
      ULONG DirectedDripsTransition : 1;
      ULONG Reserved2 : 8;
    } DUMMYSTRUCTNAME;
    ULONG ContextAsUlong;
  } DUMMYUNIONNAME;
} SYSTEM_POWER_STATE_CONTEXT, *PSYSTEM_POWER_STATE_CONTEXT;