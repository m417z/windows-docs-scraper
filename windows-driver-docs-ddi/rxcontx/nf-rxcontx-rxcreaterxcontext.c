PRX_CONTEXT RxCreateRxContext(
  [in, optional] IN PIRP                 Irp,
  [in]           IN PRDBSS_DEVICE_OBJECT RxDeviceObject,
  [in]           IN ULONG                InitialContextFlags
);