typedef struct _TIME_OF_DAY_INFO {
  DWORD tod_elapsedt;
  DWORD tod_msecs;
  DWORD tod_hours;
  DWORD tod_mins;
  DWORD tod_secs;
  DWORD tod_hunds;
  LONG  tod_timezone;
  DWORD tod_tinterval;
  DWORD tod_day;
  DWORD tod_month;
  DWORD tod_year;
  DWORD tod_weekday;
} TIME_OF_DAY_INFO, *PTIME_OF_DAY_INFO, *LPTIME_OF_DAY_INFO;