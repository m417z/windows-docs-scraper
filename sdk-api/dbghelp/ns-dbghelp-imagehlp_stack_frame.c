typedef struct _IMAGEHLP_STACK_FRAME {
  ULONG64 InstructionOffset;
  ULONG64 ReturnOffset;
  ULONG64 FrameOffset;
  ULONG64 StackOffset;
  ULONG64 BackingStoreOffset;
  ULONG64 FuncTableEntry;
  ULONG64 Params[4];
  ULONG64 Reserved[5];
  BOOL    Virtual;
  ULONG   Reserved2;
} IMAGEHLP_STACK_FRAME, *PIMAGEHLP_STACK_FRAME;