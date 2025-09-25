typedef struct _STOR_POFX_DEVICE_V3 {
  ULONG               Version;
  ULONG               Size;
  ULONG               ComponentCount;
  ULONG               Flags;
  union {
    ULONG UnitMinIdleTimeoutInMS;
    ULONG AdapterIdleTimeoutInMS;
  };
  ULONG               MinimumPowerCyclePeriodInMS;
  STOR_POFX_COMPONENT Components[ANYSIZE_ARRAY];
} STOR_POFX_DEVICE_V3, *PSTOR_POFX_DEVICE_V3;