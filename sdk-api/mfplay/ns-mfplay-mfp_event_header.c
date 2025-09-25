typedef struct MFP_EVENT_HEADER {
  MFP_EVENT_TYPE        eEventType;
  HRESULT               hrEvent;
  IMFPMediaPlayer       *pMediaPlayer;
  MFP_MEDIAPLAYER_STATE eState;
  IPropertyStore        *pPropertyStore;
} MFP_EVENT_HEADER;