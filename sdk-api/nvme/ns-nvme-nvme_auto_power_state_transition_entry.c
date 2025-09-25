typedef struct {
  ULONG Reserved0 : 3;
  ULONG IdleTransitionPowerState : 5;
  ULONG IdleTimePriorToTransition : 24;
  ULONG Reserved1;
} NVME_AUTO_POWER_STATE_TRANSITION_ENTRY, *PNVME_AUTO_POWER_STATE_TRANSITION_ENTRY;