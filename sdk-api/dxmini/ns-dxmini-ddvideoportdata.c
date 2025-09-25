typedef struct DDVIDEOPORTDATA {
  DWORD dwVideoPortId;
  DWORD dwVPFlags;
  DWORD dwOriginOffset;
  DWORD dwHeight;
  DWORD dwVBIHeight;
  ULONG dwDriverReserved1;
  ULONG dwDriverReserved2;
  ULONG dwDriverReserved3;
} DDVIDEOPORTDATA, *LPDDVIDEOPORTDATA;