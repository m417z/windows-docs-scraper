typedef struct tagEMREOF {
  EMR   emr;
  DWORD nPalEntries;
  DWORD offPalEntries;
  DWORD nSizeLast;
} EMREOF, *PEMREOF;