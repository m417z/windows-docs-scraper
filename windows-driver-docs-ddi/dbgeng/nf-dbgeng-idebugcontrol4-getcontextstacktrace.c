HRESULT GetContextStackTrace(
  [in, optional]  PVOID              StartContext,
  [in]            ULONG              StartContextSize,
  [out, optional] PDEBUG_STACK_FRAME Frames,
  [in]            ULONG              FramesSize,
  [out, optional] PVOID              FrameContexts,
  [in]            ULONG              FrameContextsSize,
  [in]            ULONG              FrameContextsEntrySize,
  [out, optional] PULONG             FramesFilled
);