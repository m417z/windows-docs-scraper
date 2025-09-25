NTSYSAPI USHORT RtlCaptureStackBackTrace(
  [in]            ULONG  FramesToSkip,
  [in]            ULONG  FramesToCapture,
  [out]           PVOID  *BackTrace,
  [out, optional] PULONG BackTraceHash
);