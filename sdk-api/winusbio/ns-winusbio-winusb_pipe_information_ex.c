typedef struct _WINUSB_PIPE_INFORMATION_EX {
  USBD_PIPE_TYPE PipeType;
  UCHAR          PipeId;
  USHORT         MaximumPacketSize;
  UCHAR          Interval;
  ULONG          MaximumBytesPerInterval;
} WINUSB_PIPE_INFORMATION_EX, *PWINUSB_PIPE_INFORMATION_EX;