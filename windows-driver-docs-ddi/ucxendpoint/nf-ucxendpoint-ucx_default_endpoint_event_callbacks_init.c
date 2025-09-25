VOID UCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS_INIT(
  [out] PUCX_DEFAULT_ENDPOINT_EVENT_CALLBACKS   Callbacks,
  [in]  PFN_UCX_ENDPOINT_PURGE                  EvtEndpointPurge,
  [in]  PFN_UCX_ENDPOINT_START                  EvtEndpointStart,
  [in]  PFN_UCX_ENDPOINT_ABORT                  EvtEndpointAbort,
  [in]  PFN_UCX_ENDPOINT_OK_TO_CANCEL_TRANSFERS EvtEndpointOkToCancelTransfers,
  [in]  PFN_UCX_DEFAULT_ENDPOINT_UPDATE         EvtDefaultEndpointUpdate
);