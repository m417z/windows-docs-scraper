MINIPORT_WDI_ALLOCATE_ADAPTER MiniportWdiAllocateAdapter;

NDIS_STATUS MiniportWdiAllocateAdapter(
  NDIS_HANDLE NdisMiniportHandle,
  NDIS_HANDLE MiniportDriverContext,
  PNDIS_MINIPORT_INIT_PARAMETERS MiniportInitParameters,
  PNDIS_WDI_INIT_PARAMETERS NdisWdiInitParameters,
  PNDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES RegistrationAttributes
)
{...}