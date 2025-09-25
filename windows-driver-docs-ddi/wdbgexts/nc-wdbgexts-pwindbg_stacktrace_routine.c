PWINDBG_STACKTRACE_ROUTINE PwindbgStacktraceRoutine;

ULONG PwindbgStacktraceRoutine(
  [in]  ULONG FramePointer,
  [in]  ULONG StackPointer,
  [in]  ULONG ProgramCounter,
  [out] PEXTSTACKTRACE StackFrames,
  [in]  ULONG Frames
)
{...}