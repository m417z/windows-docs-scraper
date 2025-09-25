typedef struct _KDHELP64 {
  DWORD64 Thread;
  DWORD   ThCallbackStack;
  DWORD   ThCallbackBStore;
  DWORD   NextCallback;
  DWORD   FramePointer;
  DWORD64 KiCallUserMode;
  DWORD64 KeUserCallbackDispatcher;
  DWORD64 SystemRangeStart;
  DWORD64 KiUserExceptionDispatcher;
  DWORD64 StackBase;
  DWORD64 StackLimit;
  DWORD   BuildVersion;
  DWORD   RetpolineStubFunctionTableSize;
  DWORD64 RetpolineStubFunctionTable;
  DWORD   RetpolineStubOffset;
  DWORD   RetpolineStubSize;
  DWORD64 Reserved0[2];
} KDHELP64, *PKDHELP64;