typedef enum _STREAM_MINIDRIVER_STREAM_NOTIFICATION_TYPE {
  ReadyForNextStreamDataRequest,
  ReadyForNextStreamControlRequest,
  HardwareStarved,
  StreamRequestComplete,
  SignalMultipleStreamEvents,
  SignalStreamEvent,
  DeleteStreamEvent,
  StreamNotificationMaximum
} STREAM_MINIDRIVER_STREAM_NOTIFICATION_TYPE, *PSTREAM_MINIDRIVER_STREAM_NOTIFICATION_TYPE;