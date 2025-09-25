typedef struct _CMC_STATUS_INFO {
  DWORD  dwStatus;
  DWORD  cBodyList;
  DWORD  *rgdwBodyList;
  LPWSTR pwszStatusString;
  DWORD  dwOtherInfoChoice;
  union {
    DWORD          dwFailInfo;
    PCMC_PEND_INFO pPendInfo;
  } DUMMYUNIONNAME;
} CMC_STATUS_INFO, *PCMC_STATUS_INFO;