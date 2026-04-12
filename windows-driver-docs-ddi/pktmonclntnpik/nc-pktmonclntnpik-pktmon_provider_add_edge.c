PKTMON_PROVIDER_ADD_EDGE PktmonProviderAddEdge;

NTSTATUS PktmonProviderAddEdge(
  VOID *ProviderBindingContext,
  HANDLE CompHandle,
  const PKTMON_EDGE_IN *Edge,
  HANDLE *EdgeHandle
)
{...}