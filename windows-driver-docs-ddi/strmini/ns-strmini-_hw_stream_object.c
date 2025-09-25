typedef struct _HW_STREAM_OBJECT {
  ULONG                          SizeOfThisPacket;
  ULONG                          StreamNumber;
  PVOID                          HwStreamExtension;
  PHW_RECEIVE_STREAM_DATA_SRB    ReceiveDataPacket;
  PHW_RECEIVE_STREAM_CONTROL_SRB ReceiveControlPacket;
  HW_CLOCK_OBJECT                HwClockObject;
  BOOLEAN                        Dma;
  BOOLEAN                        Pio;
  PVOID                          HwDeviceExtension;
  ULONG                          StreamHeaderMediaSpecific;
  ULONG                          StreamHeaderWorkspace;
  BOOLEAN                        Allocator;
  PHW_EVENT_ROUTINE              HwEventRoutine;
  ULONG                          Reserved[2];
} HW_STREAM_OBJECT, *PHW_STREAM_OBJECT;