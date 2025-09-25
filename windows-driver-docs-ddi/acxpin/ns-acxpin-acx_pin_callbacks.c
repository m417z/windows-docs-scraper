typedef struct _ACX_PIN_CALLBACKS {
  ULONG                                      Size;
  PFN_ACX_PIN_SET_DATAFORMAT                 EvtAcxPinSetDataFormat;
  PFN_ACX_PIN_RETRIEVE_NAME                  EvtAcxPinRetrieveName;
  PFN_ACX_PIN_RETRIEVE_JACK_SINK_INFO        EvtAcxPinRetrieveJackSinkInfo;
  PFN_ACX_OBJECT_PROCESS_REQUEST             EvtAcxPinProcessJackRequest;
  PFN_ACX_PIN_CONNECTED                      EvtAcxPinConnected;
  PFN_ACX_PIN_DISCONNECTED                   EvtAcxPinDisconnected;
  PFN_ACX_PIN_DATAFORMAT_CHANGE_NOTIFICATION EvtAcxPinDataFormatChangeNotification;
} ACX_PIN_CALLBACKS, *PACX_PIN_CALLBACKS;