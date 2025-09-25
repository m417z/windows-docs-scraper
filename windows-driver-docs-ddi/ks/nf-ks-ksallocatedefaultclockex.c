KSDDKAPI NTSTATUS KsAllocateDefaultClockEx(
  [out]          PKSDEFAULTCLOCK     *DefaultClock,
  [in, optional] PVOID               Context,
  [in, optional] PFNKSSETTIMER       SetTimer,
  [in, optional] PFNKSCANCELTIMER    CancelTimer,
  [in, optional] PFNKSCORRELATEDTIME CorrelatedTime,
  [in, optional] const KSRESOLUTION  *Resolution,
  [in]           ULONG               Flags
);