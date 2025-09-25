typedef struct MFP_MF_EVENT {
  MFP_EVENT_HEADER header;
  MediaEventType   MFEventType;
  IMFMediaEvent    *pMFMediaEvent;
  IMFPMediaItem    *pMediaItem;
} MFP_MF_EVENT;