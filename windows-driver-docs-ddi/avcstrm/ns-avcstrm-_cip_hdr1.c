typedef struct _CIP_HDR1 {
  ULONG DBC : 8;
  ULONG Rsv00 : 2;
  ULONG SPH : 1;
  ULONG QPC : 3;
  ULONG FN : 2;
  ULONG DBS : 8;
  ULONG SID : 6;
  ULONG Bit00 : 2;
} CIP_HDR1, *PCIP_HDR1;