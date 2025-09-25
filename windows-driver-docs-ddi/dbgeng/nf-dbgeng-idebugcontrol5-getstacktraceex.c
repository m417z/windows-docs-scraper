HRESULT GetStackTraceEx(
  [in]            ULONG64               FrameOffset,
  [in]            ULONG64               StackOffset,
  [in]            ULONG64               InstructionOffset,
  [out, writes]   PDEBUG_STACK_FRAME_EX Frames,
  [in]            ULONG                 FramesSize,
  [out, optional] PULONG                FramesFilled
);