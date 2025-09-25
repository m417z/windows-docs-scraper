typedef struct _KDHELP {
  DWORD Thread;
  DWORD ThCallbackStack;
  DWORD NextCallback;
  DWORD FramePointer;
  DWORD KiCallUserMode;
  DWORD KeUserCallbackDispatcher;
  DWORD SystemRangeStart;
  DWORD ThCallbackBStore;
  DWORD KiUserExceptionDispatcher;
  DWORD StackBase;
  DWORD StackLimit;
  DWORD Reserved[5];
} KDHELP, *PKDHELP;