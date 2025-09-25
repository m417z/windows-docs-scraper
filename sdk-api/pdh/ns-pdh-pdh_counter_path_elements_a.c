typedef struct _PDH_COUNTER_PATH_ELEMENTS_A {
  LPSTR szMachineName;
  LPSTR szObjectName;
  LPSTR szInstanceName;
  LPSTR szParentInstance;
  DWORD dwInstanceIndex;
  LPSTR szCounterName;
} PDH_COUNTER_PATH_ELEMENTS_A, *PPDH_COUNTER_PATH_ELEMENTS_A;