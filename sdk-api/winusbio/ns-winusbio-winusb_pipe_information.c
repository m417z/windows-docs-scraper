typedef struct _WINUSB_PIPE_INFORMATION {
  USBD_PIPE_TYPE PipeType;
  UCHAR          PipeId;
  USHORT         MaximumPacketSize;
  UCHAR          Interval;
} WINUSB_PIPE_INFORMATION, *PWINUSB_PIPE_INFORMATION;