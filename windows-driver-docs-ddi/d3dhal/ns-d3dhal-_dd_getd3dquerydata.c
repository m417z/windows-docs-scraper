typedef struct _DD_GETD3DQUERYDATA {
  DD_GETDRIVERINFO2DATA gdi2;
  union {
    DWORD        dwQueryIndex;
    D3DQUERYTYPE QueryType;
  };
} DD_GETD3DQUERYDATA;