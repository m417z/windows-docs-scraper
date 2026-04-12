PKTMON_PROVIDER_REGISTER_COMPONENT PktmonProviderRegisterComponent;

NTSTATUS PktmonProviderRegisterComponent(
  VOID *ProviderBindingContext,
  const PKTMON_COMPONENT_IN *Component,
  HANDLE *CompHandle
)
{...}