typedef struct _WTS_TIME_ZONE_INFORMATION {
  LONG           Bias;
  WCHAR          StandardName[32];
  WTS_SYSTEMTIME StandardDate;
  LONG           StandardBias;
  WCHAR          DaylightName[32];
  WTS_SYSTEMTIME DaylightDate;
  LONG           DaylightBias;
} _WTS_TIME_ZONE_INFORMATION, WTS_TIME_ZONE_INFORMATION, *PWTS_TIME_ZONE_INFORMATION, _WRDS_TIME_ZONE_INFORMATION;