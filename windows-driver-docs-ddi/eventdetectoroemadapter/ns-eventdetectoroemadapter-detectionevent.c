typedef struct __MIDL___MIDL_itf_eventdetectoroemadapter_0000_0000_0003 {
  DETECTIONEVENTID EventId;
  EVENTFEATURES    EventFeat;
  EVENTPROVIDERID  ProviderId;
  WCHAR            DisplayName[100];
  BOOL             UserModelValid;
} DETECTIONEVENT;