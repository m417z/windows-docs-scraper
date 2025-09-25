typedef struct _DEBUG_STACK_FRAME_EX {
  ULONG64 InstructionOffset;
  ULONG64 ReturnOffset;
  ULONG64 FrameOffset;
  ULONG64 StackOffset;
  ULONG64 FuncTableEntry;
  ULONG64 Params[4];
  ULONG64 Reserved[6];
  BOOL    Virtual;
  ULONG   FrameNumber;
  ULONG   InlineFrameContext;
  ULONG   Reserved1;
} DEBUG_STACK_FRAME_EX, *PDEBUG_STACK_FRAME_EX;