BOOL TzSpecificLocalTimeToSystemTime(
  [in, optional] const TIME_ZONE_INFORMATION *lpTimeZoneInformation,
  [in]           const SYSTEMTIME            *lpLocalTime,
  [out]          LPSYSTEMTIME                lpUniversalTime
);