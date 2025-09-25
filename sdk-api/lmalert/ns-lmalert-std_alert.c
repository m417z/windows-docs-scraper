typedef struct _STD_ALERT {
  DWORD alrt_timestamp;
  WCHAR alrt_eventname[EVLEN + 1];
  WCHAR alrt_servicename[SNLEN + 1];
} STD_ALERT, *PSTD_ALERT, *LPSTD_ALERT;