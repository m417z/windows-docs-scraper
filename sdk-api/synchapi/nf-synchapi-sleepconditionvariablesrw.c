BOOL SleepConditionVariableSRW(
  [in, out] PCONDITION_VARIABLE ConditionVariable,
  [in, out] PSRWLOCK            SRWLock,
  [in]      DWORD               dwMilliseconds,
  [in]      ULONG               Flags
);