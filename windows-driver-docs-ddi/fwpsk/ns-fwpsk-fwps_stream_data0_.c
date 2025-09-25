typedef struct FWPS_STREAM_DATA0_ {
  UINT32                   flags;
  FWPS_STREAM_DATA_OFFSET0 dataOffset;
  SIZE_T                   dataLength;
  NET_BUFFER_LIST          *netBufferListChain;
} FWPS_STREAM_DATA0;