typedef struct _WRDS_DYNAMIC_TIME_ZONE_INFORMATION {
  LONG           Bias;
  WCHAR          StandardName[32];
  WTS_SYSTEMTIME StandardDate;
  LONG           StandardBias;
  WCHAR          DaylightName[32];
  WTS_SYSTEMTIME DaylightDate;
  LONG           DaylightBias;
  WCHAR          TimeZoneKeyName[128];
  USHORT         DynamicDaylightTimeDisabled;
} WRDS_DYNAMIC_TIME_ZONE_INFORMATION, *PWRDS_DYNAMIC_TIME_ZONE_INFORMATION;