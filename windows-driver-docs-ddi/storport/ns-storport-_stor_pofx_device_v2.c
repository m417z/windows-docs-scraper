typedef struct _STOR_POFX_DEVICE_V2 {
  ULONG               Version;
  ULONG               Size;
  ULONG               ComponentCount;
  ULONG               Flags;
  union {
    ULONG UnitMinIdleTimeoutInMS;
    ULONG AdapterIdleTimeoutInMS;
  };
  STOR_POFX_COMPONENT Components[ANYSIZE_ARRAY];
} STOR_POFX_DEVICE_V2, *PSTOR_POFX_DEVICE_V2;