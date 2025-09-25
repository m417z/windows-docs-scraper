typedef struct _ACX_EVENT_CALLBACKS {
  ULONG                                Size;
  PFN_ACX_EVENT_ENABLE                 EvtAcxEventEnable;
  PFN_ACX_EVENT_DISABLE                EvtAcxEventDisable;
  PFN_ACX_OBJECT_PROCESS_EVENT_REQUEST EvtAcxEventProcessRequest;
} ACX_EVENT_CALLBACKS, *PACX_EVENT_CALLBACKS;