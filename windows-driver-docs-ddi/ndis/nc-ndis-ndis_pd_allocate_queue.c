NDIS_PD_ALLOCATE_QUEUE NdisPdAllocateQueue;

NTSTATUS() NdisPdAllocateQueue(
  [in] NDIS_PD_PROVIDER_HANDLE ProviderHandle,
  [in] const NDIS_PD_QUEUE_PARAMETERS *QueueParameters,
       NDIS_PD_QUEUE **NdisPDQueue
)
{...}