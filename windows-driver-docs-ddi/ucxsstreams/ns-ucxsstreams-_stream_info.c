typedef struct _STREAM_INFO {
  ULONG    Size;
  WDFQUEUE WdfQueue;
  ULONG    StreamId;
} STREAM_INFO, *PSTREAM_INFO;