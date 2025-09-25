typedef struct _tagSTACKFRAME {
  ADDRESS AddrPC;
  ADDRESS AddrReturn;
  ADDRESS AddrFrame;
  ADDRESS AddrStack;
  PVOID   FuncTableEntry;
  DWORD   Params[4];
  BOOL    Far;
  BOOL    Virtual;
  DWORD   Reserved[3];
  KDHELP  KdHelp;
  ADDRESS AddrBStore;
} STACKFRAME, *LPSTACKFRAME;