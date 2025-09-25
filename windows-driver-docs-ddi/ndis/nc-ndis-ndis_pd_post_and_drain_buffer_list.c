NDIS_PD_POST_AND_DRAIN_BUFFER_LIST NdisPdPostAndDrainBufferList;

VOID() NdisPdPostAndDrainBufferList(
  [in, out] NDIS_PD_QUEUE *Queue,
  [in, out] PD_BUFFER **PostBufferListHead,
  [in, out] PD_BUFFER ***DrainBufferListTail,
  [in]      ULONG MaxDrainCount
)
{...}