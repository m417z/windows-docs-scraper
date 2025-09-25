typedef struct _DD_GETADAPTERGROUPDATA {
  DD_GETDRIVERINFO2DATA gdi2;
  ULONG_PTR             ulUniqueAdapterGroupId;
  DWORD                 dwReserved1;
  DWORD                 dwReserved2;
} DD_GETADAPTERGROUPDATA;