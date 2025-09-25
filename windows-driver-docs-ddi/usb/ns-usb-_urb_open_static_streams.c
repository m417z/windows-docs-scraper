struct _URB_OPEN_STATIC_STREAMS {
  struct _URB_HEADER       Hdr;
  USBD_PIPE_HANDLE         PipeHandle;
  ULONG                    NumberOfStreams;
  USHORT                   StreamInfoVersion;
  USHORT                   StreamInfoSize;
  PUSBD_STREAM_INFORMATION Streams;
};