IF_QUERY_OBJECT IfQueryObject;

NDIS_STATUS() IfQueryObject(
  [in]      NDIS_HANDLE ProviderIfContext,
  [in]      NET_IF_OBJECT_ID ObjectId,
  [in, out] PULONG pOutputBufferLength,
  [out]     PVOID pOutputBuffer
)
{...}