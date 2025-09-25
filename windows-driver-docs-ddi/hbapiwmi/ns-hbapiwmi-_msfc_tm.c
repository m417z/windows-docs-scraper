typedef struct _MSFC_TM {
  ULONG tm_sec;
  ULONG tm_min;
  ULONG tm_hour;
  ULONG tm_mday;
  ULONG tm_mon;
  ULONG tm_year;
  ULONG tm_wday;
  ULONG tm_yday;
  ULONG tm_isdst;
} MSFC_TM, *PMSFC_TM;