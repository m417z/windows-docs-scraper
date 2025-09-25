typedef struct _THERMAL_EVENT {
  ULONG  Version;
  ULONG  Size;
  ULONG  Type;
  ULONG  Temperature;
  ULONG  TripPointTemperature;
  LPWSTR Initiator;
} THERMAL_EVENT, *PTHERMAL_EVENT;