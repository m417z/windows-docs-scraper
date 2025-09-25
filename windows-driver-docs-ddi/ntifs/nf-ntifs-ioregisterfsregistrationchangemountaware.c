NTSTATUS IoRegisterFsRegistrationChangeMountAware(
  [in] PDRIVER_OBJECT          DriverObject,
  [in] PDRIVER_FS_NOTIFICATION DriverNotificationRoutine,
  [in] BOOLEAN                 SynchronizeWithMounts
);