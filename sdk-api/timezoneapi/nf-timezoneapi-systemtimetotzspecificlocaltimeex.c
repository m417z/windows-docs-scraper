BOOL SystemTimeToTzSpecificLocalTimeEx(
  [in, optional] const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation,
  [in]           const SYSTEMTIME                    *lpUniversalTime,
  [out]          LPSYSTEMTIME                        lpLocalTime
);