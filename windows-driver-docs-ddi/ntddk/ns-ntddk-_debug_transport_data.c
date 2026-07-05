typedef struct _DEBUG_TRANSPORT_DATA {
  ULONG   HwContextSize;
  ULONG   SharedVisibleDataSize;
  BOOLEAN UseSerialFraming;
  BOOLEAN ValidUSBCoreId;
  UCHAR   USBCoreId;
  BOOLEAN DevControlInitialized;
  union {
    UINT32 RawPciLocation;
    struct {
      UINT32 Segment : 16;
      UINT32 Bus : 8;
      UINT32 Device : 5;
      UINT32 Function : 3;
    } Fields;
  } DevControlPciLocation;
} DEBUG_TRANSPORT_DATA, *PDEBUG_TRANSPORT_DATA;