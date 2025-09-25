VOID NdisMSetAttributesEx(
  [in]           NDIS_HANDLE         MiniportAdapterHandle,
  [in]           NDIS_HANDLE         MiniportAdapterContext,
  [in, optional] UINT                CheckForHangTimeInSeconds,
  [in]           ULONG               AttributeFlags,
  [in, optional] NDIS_INTERFACE_TYPE AdapterType
);