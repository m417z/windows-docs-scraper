typedef struct _DD_GETEXTENDEDMODECOUNTDATA {
  DD_GETDRIVERINFO2DATA gdi2;
  DWORD                 dwModeCount;
  DWORD                 dwReserved;
} DD_GETEXTENDEDMODECOUNTDATA;