PKTMON_PROVIDER_SET_COMP_PROPERTY PktmonProviderSetCompProperty;

NTSTATUS PktmonProviderSetCompProperty(
  VOID *ProviderBindingContext,
  HANDLE CompHandle,
  const PKTMON_COMP_PROPERTY_IN *Property
)
{...}