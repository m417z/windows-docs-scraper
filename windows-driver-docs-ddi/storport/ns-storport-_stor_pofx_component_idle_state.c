typedef struct _STOR_POFX_COMPONENT_IDLE_STATE {
  ULONG     Version;
  ULONG     Size;
  ULONGLONG TransitionLatency;
  ULONGLONG ResidencyRequirement;
  ULONG     NominalPower;
} STOR_POFX_COMPONENT_IDLE_STATE, *PSTOR_POFX_COMPONENT_IDLE_STATE;