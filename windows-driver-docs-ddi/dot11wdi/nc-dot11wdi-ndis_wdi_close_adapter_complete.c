NDIS_WDI_CLOSE_ADAPTER_COMPLETE NdisWdiCloseAdapterComplete;

void NdisWdiCloseAdapterComplete(
  [in] NDIS_HANDLE MiniportAdapterHandle,
  [in] NDIS_STATUS CompletionStatus
)
{...}