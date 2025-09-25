typedef enum _WDF_IO_FORWARD_PROGRESS_ACTION {
  WdfIoForwardProgressActionInvalid = 0x0,
  WdfIoForwardProgressActionFailRequest,
  WdfIoForwardProgressActionUseReservedRequest
} WDF_IO_FORWARD_PROGRESS_ACTION;