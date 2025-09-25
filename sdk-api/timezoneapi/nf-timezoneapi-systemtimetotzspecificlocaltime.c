BOOL SystemTimeToTzSpecificLocalTime(
  [in, optional] const TIME_ZONE_INFORMATION *lpTimeZoneInformation,
  [in]           const SYSTEMTIME            *lpUniversalTime,
  [out]          LPSYSTEMTIME                lpLocalTime
);