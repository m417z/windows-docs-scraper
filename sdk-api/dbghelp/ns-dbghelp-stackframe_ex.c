typedef struct _tagSTACKFRAME_EX {
  ADDRESS64 AddrPC;
  ADDRESS64 AddrReturn;
  ADDRESS64 AddrFrame;
  ADDRESS64 AddrStack;
  ADDRESS64 AddrBStore;
  PVOID     FuncTableEntry;
  DWORD64   Params[4];
  BOOL      Far;
  BOOL      Virtual;
  DWORD64   Reserved[3];
  KDHELP64  KdHelp;
  DWORD     StackFrameSize;
  DWORD     InlineFrameContext;
} STACKFRAME_EX, *LPSTACKFRAME_EX;