typedef struct _BATTERY_WMI_STATUS {
  ULONG   Tag;
  ULONG   RemainingCapacity;
  LONG    ChargeRate;
  LONG    DischargeRate;
  ULONG   Voltage;
  BOOLEAN PowerOnline;
  BOOLEAN Charging;
  BOOLEAN Discharging;
  BOOLEAN Critical;
} BATTERY_WMI_STATUS, *PBATTERY_WMI_STATUS;