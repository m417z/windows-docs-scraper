EVT_UCX_ENDPOINT_STATIC_STREAMS_ADD EvtUcxEndpointStaticStreamsAdd;

NTSTATUS EvtUcxEndpointStaticStreamsAdd(
  [in] UCXENDPOINT UcxEndpoint,
  [in] ULONG NumberOfStreams,
  [in] PUCXSSTREAMS_INIT UcxStaticStreamsInit
)
{...}