NTSYSAPI NTSTATUS RtlRunOnceComplete(
  [in, out]      PRTL_RUN_ONCE RunOnce,
  [in]           ULONG         Flags,
  [in, optional] PVOID         Context
);