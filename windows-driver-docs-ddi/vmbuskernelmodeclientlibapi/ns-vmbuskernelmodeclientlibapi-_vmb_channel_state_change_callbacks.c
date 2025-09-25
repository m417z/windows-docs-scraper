typedef struct _VMB_CHANNEL_STATE_CHANGE_CALLBACKS {
  ULONG                        Version;
  ULONG                        Size;
  PFN_VMB_CHANNEL_OPENED       EvtChannelOpened;
  PFN_VMB_CHANNEL_CLOSED       EvtChannelClosed;
  PFN_VMB_CHANNEL_SUSPEND      EvtChannelSuspend;
  PFN_VMB_CHANNEL_STARTED      EvtChannelStarted;
  PFN_VMB_CHANNEL_POST_STARTED EvtChannelPostStarted;
} VMB_CHANNEL_STATE_CHANGE_CALLBACKS, *PVMB_CHANNEL_STATE_CHANGE_CALLBACKS;