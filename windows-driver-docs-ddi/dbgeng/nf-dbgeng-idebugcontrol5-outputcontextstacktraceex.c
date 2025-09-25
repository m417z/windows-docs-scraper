HRESULT OutputContextStackTraceEx(
  [in] ULONG                 OutputControl,
  [in] PDEBUG_STACK_FRAME_EX Frames,
  [in] ULONG                 FramesSize,
  [in] PVOID                 FrameContexts,
  [in] ULONG                 FrameContextsSize,
  [in] ULONG                 FrameContextsEntrySize,
  [in] ULONG                 Flags
);