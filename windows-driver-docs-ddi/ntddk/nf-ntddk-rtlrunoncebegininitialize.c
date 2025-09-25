NTSYSAPI NTSTATUS RtlRunOnceBeginInitialize(
  [in, out] PRTL_RUN_ONCE RunOnce,
  [in]      ULONG         Flags,
  [out]     PVOID         *Context
);