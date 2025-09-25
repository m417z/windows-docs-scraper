typedef struct _SIP_CAP_SET_V3 {
  DWORD cbSize;
  DWORD dwVersion;
  BOOL  isMultiSign;
  union {
    DWORD dwFlags;
    DWORD dwReserved;
  };
} SIP_CAP_SET_V3, *PSIP_CAP_SET_V3;