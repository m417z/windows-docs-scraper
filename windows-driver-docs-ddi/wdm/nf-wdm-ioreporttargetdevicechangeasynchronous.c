NTSTATUS IoReportTargetDeviceChangeAsynchronous(
  [in]           PDEVICE_OBJECT                   PhysicalDeviceObject,
  [in]           PVOID                            NotificationStructure,
  [in, optional] PDEVICE_CHANGE_COMPLETE_CALLBACK Callback,
  [in, out]      PVOID                            Context
);