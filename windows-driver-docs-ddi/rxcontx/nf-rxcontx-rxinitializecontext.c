VOID RxInitializeContext(
  [in, optional] IN PIRP                 Irp,
  [in]           IN PRDBSS_DEVICE_OBJECT RxDeviceObject,
  [in]           IN ULONG                InitialContextFlags,
  [in, out]      IN OUT PRX_CONTEXT      RxContext
);