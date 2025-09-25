typedef struct FWPS_STREAM_DATA_OFFSET0_ {
  NET_BUFFER_LIST *netBufferList;
  NET_BUFFER      *netBuffer;
  MDL             *mdl;
  UINT32          mdlOffset;
  UINT32          netBufferOffset;
  SIZE_T          streamDataOffset;
} FWPS_STREAM_DATA_OFFSET0;