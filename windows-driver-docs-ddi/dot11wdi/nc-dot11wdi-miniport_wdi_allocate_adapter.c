MINIPORT_WDI_ALLOCATE_ADAPTER MiniportWdiAllocateAdapter;

NDIS_STATUS MiniportWdiAllocateAdapter(
  [in]      NDIS_HANDLE NdisMiniportHandle,
  [in]      NDIS_HANDLE MiniportDriverContext,
  [in]      PNDIS_MINIPORT_INIT_PARAMETERS MiniportInitParameters,
  [in]      PNDIS_WDI_INIT_PARAMETERS NdisWdiInitParameters,
  [in, out] PNDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES RegistrationAttributes
)
{...}