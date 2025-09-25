VOID __RxFillAndInstallFastIoDispatch(
  [in]      IN PRDBSS_DEVICE_OBJECT  RxDeviceObject,
  [in, out] IN OUT PFAST_IO_DISPATCH FastIoDispatch,
  [in]      IN ULONG                 FastIoDispatchSize
);