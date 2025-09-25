typedef struct _PDH_COUNTER_PATH_ELEMENTS_W {
  LPWSTR szMachineName;
  LPWSTR szObjectName;
  LPWSTR szInstanceName;
  LPWSTR szParentInstance;
  DWORD  dwInstanceIndex;
  LPWSTR szCounterName;
} PDH_COUNTER_PATH_ELEMENTS_W, *PPDH_COUNTER_PATH_ELEMENTS_W;