typedef enum _WHEAP_DPC_ERROR_EVENT_TYPE {
  WheapDpcErrNoErr,
  WheapDpcErrBusNotFound,
  WheapDpcErrDpcedSubtree,
  WheapDpcErrDeviceIdBad,
  WheapDpcErrResetFailed,
  WheapDpcErrNoChildren
} WHEAP_DPC_ERROR_EVENT_TYPE, *PWHEAP_DPC_ERROR_EVENT_TYPE;