typedef struct _NSPV2_ROUTINE {
  DWORD                       cbSize;
  DWORD                       dwMajorVersion;
  DWORD                       dwMinorVersion;
  LPNSPV2STARTUP              NSPv2Startup;
  LPNSPV2CLEANUP              NSPv2Cleanup;
  LPNSPV2LOOKUPSERVICEBEGIN   NSPv2LookupServiceBegin;
  LPNSPV2LOOKUPSERVICENEXTEX  NSPv2LookupServiceNextEx;
  LPNSPV2LOOKUPSERVICEEND     NSPv2LookupServiceEnd;
  LPNSPV2SETSERVICEEX         NSPv2SetServiceEx;
  LPNSPV2CLIENTSESSIONRUNDOWN NSPv2ClientSessionRundown;
} NSPV2_ROUTINE, *PNSPV2_ROUTINE, *LPNSPV2_ROUTINE;