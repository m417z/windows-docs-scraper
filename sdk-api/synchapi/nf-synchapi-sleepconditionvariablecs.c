BOOL SleepConditionVariableCS(
  [in, out] PCONDITION_VARIABLE ConditionVariable,
  [in, out] PCRITICAL_SECTION   CriticalSection,
  [in]      DWORD               dwMilliseconds
);