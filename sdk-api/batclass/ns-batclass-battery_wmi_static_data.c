typedef struct _BATTERY_WMI_STATIC_DATA {
  ULONG                   Tag;
  WCHAR                   ManufactureDate[25];
  BATTERY_REPORTING_SCALE Granularity[4];
  ULONG                   Capabilities;
  UCHAR                   Technology;
  ULONG                   Chemistry;
  ULONG                   DesignedCapacity;
  ULONG                   DefaultAlert1;
  ULONG                   DefaultAlert2;
  ULONG                   CriticalBias;
  WCHAR                   Strings[1];
} BATTERY_WMI_STATIC_DATA, *PBATTERY_WMI_STATIC_DATA;