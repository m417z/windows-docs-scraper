typedef struct _BATTERY_STATUS {
  ULONG PowerState;
  ULONG Capacity;
  ULONG Voltage;
  LONG  Rate;
} BATTERY_STATUS, *PBATTERY_STATUS;