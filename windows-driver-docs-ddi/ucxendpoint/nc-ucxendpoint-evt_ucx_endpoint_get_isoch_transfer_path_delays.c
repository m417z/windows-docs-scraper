EVT_UCX_ENDPOINT_GET_ISOCH_TRANSFER_PATH_DELAYS EvtUcxEndpointGetIsochTransferPathDelays;

NTSTATUS EvtUcxEndpointGetIsochTransferPathDelays(
  [in]      UCXENDPOINT UcxEndpoint,
  [in, out] PUCX_ENDPOINT_ISOCH_TRANSFER_PATH_DELAYS UcxEndpointTransferPathDelays
)
{...}