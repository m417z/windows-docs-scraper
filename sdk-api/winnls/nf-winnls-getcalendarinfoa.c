int GetCalendarInfoA(
  [in]            LCID    Locale,
  [in]            CALID   Calendar,
  [in]            CALTYPE CalType,
  [out, optional] LPSTR   lpCalData,
  [in]            int     cchData,
  [out, optional] LPDWORD lpValue
);