typedef struct _USBSCAN_PIPE_INFORMATION {
  USHORT        MaximumPacketSize;
  UCHAR         EndpointAddress;
  UCHAR         Interval;
  RAW_PIPE_TYPE PipeType;
} USBSCAN_PIPE_INFORMATION, *PUSBSCAN_PIPE_INFORMATION;