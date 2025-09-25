typedef struct _FPO_DATA {
  DWORD ulOffStart;
  DWORD cbProcSize;
  DWORD cdwLocals;
  WORD  cdwParams;
  WORD  cbProlog : 8;
  WORD  cbRegs : 3;
  WORD  fHasSEH : 1;
  WORD  fUseBP : 1;
  WORD  reserved : 1;
  WORD  cbFrame : 2;
} FPO_DATA, *PFPO_DATA;