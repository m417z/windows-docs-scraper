typedef struct _WHEAP_DPC_ERROR_EVENT {
  WHEA_EVENT_LOG_ENTRY       WheaEventLogEntry;
  WHEAP_DPC_ERROR_EVENT_TYPE ErrType;
  ULONG                      Bus;
  ULONG                      Device;
  ULONG                      Function;
  USHORT                     DeviceId;
  USHORT                     VendorId;
} WHEAP_DPC_ERROR_EVENT, *PWHEAP_DPC_ERROR_EVENT;