typedef struct MFP_RATE_SET_EVENT {
  MFP_EVENT_HEADER header;
  IMFPMediaItem    *pMediaItem;
  float            flRate;
} MFP_RATE_SET_EVENT;