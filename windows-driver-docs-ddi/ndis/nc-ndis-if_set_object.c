IF_SET_OBJECT IfSetObject;

NDIS_STATUS() IfSetObject(
  [in] NDIS_HANDLE ProviderIfContext,
  [in] NET_IF_OBJECT_ID ObjectId,
  [in] ULONG InputBufferLength,
  [in] PVOID pInputBuffer
)
{...}