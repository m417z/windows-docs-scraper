typedef enum _WDF_REQUEST_STOP_ACTION_FLAGS {
  WdfRequestStopActionInvalid,
  WdfRequestStopActionSuspend,
  WdfRequestStopActionPurge,
  WdfRequestStopRequestCancelable
} WDF_REQUEST_STOP_ACTION_FLAGS;