BOOLEAN DlSynchronizeExecution(
  PVOID                         DeviceHandle,
  VIDEO_SYNCHRONIZE_PRIORITY    Priority,
  PMINIPORT_SYNCHRONIZE_ROUTINE SynchronizeRoutine,
  PVOID                         Context,
  ULONG                         MessageNumber
);