OPEN_NDK_ADAPTER_HANDLER OpenNdkAdapterHandler;

NDIS_STATUS OpenNdkAdapterHandler(
  [in] NDIS_HANDLE MiniportAdapterContext,
  [in] PNDIS_OPEN_NDK_ADAPTER_PARAMETERS Parameters,
       NDK_ADAPTER **ppNdkAdapter
)
{...}