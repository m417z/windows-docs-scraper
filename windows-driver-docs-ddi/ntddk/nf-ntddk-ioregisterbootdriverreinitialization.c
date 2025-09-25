VOID IoRegisterBootDriverReinitialization(
  [in]           PDRIVER_OBJECT       DriverObject,
  [in]           PDRIVER_REINITIALIZE DriverReinitializationRoutine,
  [in, optional] PVOID                Context
);