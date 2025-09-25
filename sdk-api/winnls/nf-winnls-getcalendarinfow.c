int GetCalendarInfoW(
  [in]            LCID    Locale,
  [in]            CALID   Calendar,
  [in]            CALTYPE CalType,
  [out, optional] LPWSTR  lpCalData,
  [in]            int     cchData,
  [out, optional] LPDWORD lpValue
);