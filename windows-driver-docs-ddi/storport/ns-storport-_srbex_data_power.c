typedef struct _SRBEX_DATA_POWER {
  SRBEXDATATYPE           Type;
  ULONG                   Length;
  UCHAR                   SrbPowerFlags;
  UCHAR                   Reserved[3];
  STOR_DEVICE_POWER_STATE DevicePowerState;
  STOR_POWER_ACTION       PowerAction;
} SRBEX_DATA_POWER, *PSRBEX_DATA_POWER;