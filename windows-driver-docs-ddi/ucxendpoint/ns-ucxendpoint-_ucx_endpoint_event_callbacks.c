typedef struct _UCX_ENDPOINT_EVENT_CALLBACKS {
  ULONG                                           Size;
  PFN_UCX_ENDPOINT_PURGE                          EvtEndpointPurge;
  PFN_UCX_ENDPOINT_START                          EvtEndpointStart;
  PFN_UCX_ENDPOINT_ABORT                          EvtEndpointAbort;
  PFN_UCX_ENDPOINT_RESET                          EvtEndpointReset;
  PFN_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS         EvtEndpointOkToCancelTransfers;
  PFN_UCX_ENDPOINT_STATIC_STREAMS_ADD             EvtEndpointStaticStreamsAdd;
  PFN_UCX_ENDPOINT_STATIC_STREAMS_ENABLE          EvtEndpointStaticStreamsEnable;
  PFN_UCX_ENDPOINT_STATIC_STREAMS_DISABLE         EvtEndpointStaticStreamsDisable;
  HANDLE                                          Reserved1;
  PFN_UCX_ENDPOINT_GET_ISOCH_TRANSFER_PATH_DELAYS EvtEndpointGetIsochTransferPathDelays;
  PFN_UCX_ENDPOINT_SET_CHARACTERISTIC             EvtEndpointSetCharacteristic;
} UCX_ENDPOINT_EVENT_CALLBACKS, *PUCX_ENDPOINT_EVENT_CALLBACKS;