typedef struct _STREAM_DATA_INTERSECT_INFO {
  ULONG        StreamNumber;
  PKSDATARANGE DataRange;
  PVOID        DataFormatBuffer;
  ULONG        SizeOfDataFormatBuffer;
} STREAM_DATA_INTERSECT_INFO, *PSTREAM_DATA_INTERSECT_INFO;