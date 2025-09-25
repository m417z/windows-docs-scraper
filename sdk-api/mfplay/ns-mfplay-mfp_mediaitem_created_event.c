typedef struct MFP_MEDIAITEM_CREATED_EVENT {
  MFP_EVENT_HEADER header;
  IMFPMediaItem    *pMediaItem;
  DWORD_PTR        dwUserData;
} MFP_MEDIAITEM_CREATED_EVENT;