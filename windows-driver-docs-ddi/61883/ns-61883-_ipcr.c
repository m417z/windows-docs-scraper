typedef struct _IPCR {
  ULONG Reserved0 : 16;
  ULONG Channel : 6;
  ULONG Reserved1 : 2;
  ULONG PPCCounter : 6;
  ULONG BCCCounter : 1;
  ULONG OnLine : 1;
} IPCR, *PIPCR;