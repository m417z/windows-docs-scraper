typedef struct _SIP_CAP_SET_V2 {
  DWORD cbSize;
  DWORD dwVersion;
  BOOL  isMultiSign;
  DWORD dwReserved;
} SIP_CAP_SET_V2, *PSIP_CAP_SET_V2;