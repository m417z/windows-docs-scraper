typedef enum _WDF_REQUEST_STOP_ACTION_FLAGS {
  WdfRequestStopActionInvalid = 0,
  WdfRequestStopActionSuspend = 0x01,
  WdfRequestStopActionPurge = 0x2,
  WdfRequestStopRequestCancelable = 0x10000000
} WDF_REQUEST_STOP_ACTION_FLAGS;