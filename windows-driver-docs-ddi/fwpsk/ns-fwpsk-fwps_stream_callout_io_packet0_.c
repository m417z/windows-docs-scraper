typedef struct FWPS_STREAM_CALLOUT_IO_PACKET0_ {
  FWPS_STREAM_DATA0       *streamData;
  SIZE_T                  missedBytes;
  UINT32                  countBytesRequired;
  SIZE_T                  countBytesEnforced;
  FWPS_STREAM_ACTION_TYPE streamAction;
} FWPS_STREAM_CALLOUT_IO_PACKET0;