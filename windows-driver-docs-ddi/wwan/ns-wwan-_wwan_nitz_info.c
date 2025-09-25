typedef struct _WWAN_NITZ_INFO {
  ULONG Year;
  ULONG Month;
  ULONG Day;
  ULONG Hour;
  ULONG Minute;
  ULONG Second;
  ULONG TimeZoneOffsetMinutes;
  ULONG DaylightSavingTimeOffsetMinutes;
  ULONG DataClasses;
} WWAN_NITZ_INFO, *PWWAN_NITZ_INFO;