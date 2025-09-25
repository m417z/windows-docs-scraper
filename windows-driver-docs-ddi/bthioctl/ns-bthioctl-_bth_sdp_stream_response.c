typedef struct _BTH_SDP_STREAM_RESPONSE {
  ULONG requiredSize;
  ULONG responseSize;
  UCHAR response[1];
} BTH_SDP_STREAM_RESPONSE, *PBTH_SDP_STREAM_RESPONSE;