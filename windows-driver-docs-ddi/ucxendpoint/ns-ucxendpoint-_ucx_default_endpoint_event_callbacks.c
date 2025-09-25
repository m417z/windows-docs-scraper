typedef struct _UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS {
  ULONG                                   Size;
  PFN_UCX_ENDPOINT_PURGE                  EvtEndpointPurge;
  PFN_UCX_ENDPOINT_START                  EvtEndpointStart;
  PFN_UCX_ENDPOINT_ABORT                  EvtEndpointAbort;
  PFN_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS EvtEndpointOkToCancelTransfers;
  PFN_UCX_DEFAULT_ENDPOINT_UPDATE         EvtDefaultEndpointUpdate;
  HANDLE                                  Reserved1;
} UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS, *PUCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS;