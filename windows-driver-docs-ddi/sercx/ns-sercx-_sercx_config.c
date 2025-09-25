typedef struct _SERCX_CONFIG {
  ULONG                     Size;
  WDF_TRI_STATE             PowerManaged;
  PFN_SERCX_FILEOPEN        EvtSerCxFileOpen;
  PFN_SERCX_FILECLOSE       EvtSerCxFileClose;
  PFN_SERCX_FILECLEANUP     EvtSerCxFileCleanup;
  PFN_SERCX_TRANSMIT        EvtSerCxTransmit;
  PFN_SERCX_RECEIVE         EvtSerCxReceive;
  PFN_SERCX_WAITMASK        EvtSerCxWaitmask;
  PFN_SERCX_PURGE           EvtSerCxPurge;
  PFN_SERCX_CONTROL         EvtSerCxControl;
  PFN_SERCX_APPLY_CONFIG    EvtSerCxApplyConfig;
  PFN_SERCX_TRANSMIT_CANCEL EvtSerCxTransmitCancel;
  PFN_SERCX_RECEIVE_CANCEL  EvtSerCxReceiveCancel;
} SERCX_CONFIG, *PSERCX_CONFIG;