NTSYSAPI WORD RtlCaptureStackBackTrace(
  [in]            DWORD  FramesToSkip,
  [in]            DWORD  FramesToCapture,
  [out]           PVOID  *BackTrace,
  [out, optional] PDWORD BackTraceHash
);