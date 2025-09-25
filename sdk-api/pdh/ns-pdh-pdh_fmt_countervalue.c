typedef struct _PDH_FMT_COUNTERVALUE {
  DWORD CStatus;
  union {
    LONG     longValue;
    double   doubleValue;
    LONGLONG largeValue;
    LPCSTR   AnsiStringValue;
    LPCWSTR  WideStringValue;
  };
} PDH_FMT_COUNTERVALUE, *PPDH_FMT_COUNTERVALUE;