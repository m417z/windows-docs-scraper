int GetCalendarInfoEx(
  [in, optional]  LPCWSTR lpLocaleName,
  [in]            CALID   Calendar,
  [in, optional]  LPCWSTR lpReserved,
  [in]            CALTYPE CalType,
  [out, optional] LPWSTR  lpCalData,
  [in]            int     cchData,
  [out, optional] LPDWORD lpValue
);