typedef enum _PosEventType {
  InvalidEvent,
  _MinEventType,
  ReleaseDeviceRequested,
  StatusUpdated,
  BarcodeScannerTriggerPressed,
  BarcodeScannerTriggerReleased,
  BarcodeScannerDataReceived,
  BarcodeScannerErrorOccurred,
  BarcodeScannerImagePreviewReceived,
  MagneticStripeReaderDataReceived,
  MagneticStripeReaderErrorOccurred,
  _Max
} PosEventType;