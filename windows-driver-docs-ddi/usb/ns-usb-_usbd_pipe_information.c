typedef struct _USBD_PIPE_INFORMATION {
  USHORT           MaximumPacketSize;
  UCHAR            EndpointAddress;
  UCHAR            Interval;
  USBD_PIPE_TYPE   PipeType;
  USBD_PIPE_HANDLE PipeHandle;
  ULONG            MaximumTransferSize;
  ULONG            PipeFlags;
} USBD_PIPE_INFORMATION, *PUSBD_PIPE_INFORMATION;