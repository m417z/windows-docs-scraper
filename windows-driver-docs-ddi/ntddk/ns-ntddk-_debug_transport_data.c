typedef struct _DEBUG_TRANSPORT_DATA {
  ULONG   HwContextSize;
  ULONG   SharedVisibleDataSize;
  BOOLEAN UseSerialFraming;
  BOOLEAN ValidUSBCoreId;
  UCHAR   USBCoreId;
} DEBUG_TRANSPORT_DATA, *PDEBUG_TRANSPORT_DATA;