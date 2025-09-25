typedef struct _USB_BUS_STATISTICS_0 {
  ULONG         DeviceCount;
  LARGE_INTEGER CurrentSystemTime;
  ULONG         CurrentUsbFrame;
  ULONG         BulkBytes;
  ULONG         IsoBytes;
  ULONG         InterruptBytes;
  ULONG         ControlDataBytes;
  ULONG         PciInterruptCount;
  ULONG         HardResetCount;
  ULONG         WorkerSignalCount;
  ULONG         CommonBufferBytes;
  ULONG         WorkerIdleTimeMs;
  BOOLEAN       RootHubEnabled;
  UCHAR         RootHubDevicePowerState;
  UCHAR         Unused;
  UCHAR         NameIndex;
} USB_BUS_STATISTICS_0, *PUSB_BUS_STATISTICS_0;