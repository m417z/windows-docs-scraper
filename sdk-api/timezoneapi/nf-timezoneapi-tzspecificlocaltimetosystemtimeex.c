BOOL TzSpecificLocalTimeToSystemTimeEx(
  [in, optional] const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation,
  [in]           const SYSTEMTIME                    *lpLocalTime,
  [out]          LPSYSTEMTIME                        lpUniversalTime
);