NDIS_PD_QUERY_QUEUE_DEPTH NdisPdQueryQueueDepth;

VOID() NdisPdQueryQueueDepth(
  [in]  const NDIS_PD_QUEUE *Queue,
  [out] ULONG64 *Depth
)
{...}