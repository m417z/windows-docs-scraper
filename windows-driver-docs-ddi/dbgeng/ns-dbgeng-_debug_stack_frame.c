typedef struct _DEBUG_STACK_FRAME {
  ULONG64 InstructionOffset;
  ULONG64 ReturnOffset;
  ULONG64 FrameOffset;
  ULONG64 StackOffset;
  ULONG64 FuncTableEntry;
  ULONG64 Params[4];
  ULONG64 Reserved[6];
  BOOL    Virtual;
  ULONG   FrameNumber;
} DEBUG_STACK_FRAME, *PDEBUG_STACK_FRAME;