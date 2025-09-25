typedef struct _OPCR {
  ULONG Payload : 10;
  ULONG OverheadID : 4;
  ULONG DataRate : 2;
  ULONG Channel : 6;
  ULONG Reserved : 2;
  ULONG PPCCounter : 6;
  ULONG BCCCounter : 1;
  ULONG OnLine : 1;
} OPCR, *POPCR;