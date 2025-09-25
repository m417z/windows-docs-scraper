NTSTATUS KeDelayExecutionThread(
  [in] KPROCESSOR_MODE WaitMode,
  [in] BOOLEAN         Alertable,
  [in] PLARGE_INTEGER  Interval
);