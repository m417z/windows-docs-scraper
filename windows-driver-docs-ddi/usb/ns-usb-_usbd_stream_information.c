typedef struct _USBD_STREAM_INFORMATION {
  USBD_PIPE_HANDLE PipeHandle;
  ULONG            StreamID;
  ULONG            MaximumTransferSize;
  ULONG            PipeFlags;
} USBD_STREAM_INFORMATION, *PUSBD_STREAM_INFORMATION;