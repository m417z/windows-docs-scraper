typedef struct _HW_STREAM_REQUEST_BLOCK {
  ULONG                           SizeOfThisPacket;
  SRB_COMMAND                     Command;
  NTSTATUS                        Status;
  PHW_STREAM_OBJECT               StreamObject;
  PVOID                           HwDeviceExtension;
  PVOID                           SRBExtension;
  union {
    PKSSTREAM_HEADER                       DataBufferArray;
    PHW_STREAM_DESCRIPTOR                  StreamBuffer;
    KSSTATE                                StreamState;
    PSTREAM_TIME_REFERENCE                 TimeReference;
    PSTREAM_PROPERTY_DESCRIPTOR            PropertyInfo;
    PKSDATAFORMAT                          OpenFormat;
    struct _PORT_CONFIGURATION_INFORMATION *ConfigInfo;
    HANDLE                                 MasterClockHandle;
    DEVICE_POWER_STATE                     DeviceState;
    PSTREAM_DATA_INTERSECT_INFO            IntersectInfo;
    PVOID                                  MethodInfo;
    LONG                                   FilterTypeIndex;
    BOOLEAN                                Idle;
  } CommandData;
  _CommandData                    _CommandData;
  ULONG                           NumberOfBuffers;
  ULONG                           TimeoutCounter;
  ULONG                           TimeoutOriginal;
  struct _HW_STREAM_REQUEST_BLOCK *NextSRB;
  PIRP                            Irp;
  ULONG                           Flags;
  PVOID                           HwInstanceExtension;
  union {
    ULONG NumberOfBytesToTransfer;
    ULONG ActualBytesTransferred;
  };
  PKSSCATTER_GATHER               ScatterGatherBuffer;
  ULONG                           NumberOfPhysicalPages;
  ULONG                           NumberOfScatterGatherElements;
  ULONG                           Reserved[1];
} HW_STREAM_REQUEST_BLOCK, *PHW_STREAM_REQUEST_BLOCK;