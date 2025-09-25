TDHSTATUS TdhGetEventInformation(
  [in]      PEVENT_RECORD     Event,
  [in]      ULONG             TdhContextCount,
  [in]      PTDH_CONTEXT      TdhContext,
  [out]     PTRACE_EVENT_INFO Buffer,
  [in, out] PULONG            BufferSize
);