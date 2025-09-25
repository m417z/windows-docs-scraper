HRESULT GetContextStackTraceEx(
  [in, optional]  PVOID                 StartContext,
  [in]            ULONG                 StartContextSize,
  [out, optional] PDEBUG_STACK_FRAME_EX Frames,
  [in]            ULONG                 FramesSize,
  [out, optional] PVOID                 FrameContexts,
  [in]            ULONG                 FrameContextsSize,
  [in]            ULONG                 FrameContextsEntrySize,
  [out, optional] PULONG                FramesFilled
);