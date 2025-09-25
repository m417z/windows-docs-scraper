NDIS_STATUS NdisMGetOffloadHandlers(
  [in]  IN NDIS_HANDLE                   NdisMiniportHandle,
  [in]  IN NDIS_CHIMNEY_OFFLOAD_TYPE     ChimneyType,
  [out] OUT PNDIS_OFFLOAD_EVENT_HANDLERS *OffloadHandlers
);