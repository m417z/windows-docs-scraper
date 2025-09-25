typedef enum _WDF_REQUEST_TYPE {
  WdfRequestUndefined,
  WdfRequestCreate,
  WdfRequestCleanup,
  WdfRequestRead,
  WdfRequestWrite,
  WdfRequestDeviceIoControl,
  WdfRequestClose,
  WdfRequestUsb,
  WdfRequestOther,
  WdfRequestInternalIoctl,
  WdfRequestTypeNoFormat,
  WdfRequestFlushBuffers,
  WdfRequestQueryInformation,
  WdfRequestSetInformation,
  WdfRequestMaximum
} WDF_REQUEST_TYPE, *PWDF_REQUEST_TYPE;