PFREE_DMA_BUFFER_WITH_NOTIFICATION PfreeDmaBufferWithNotification;

NTSTATUS PfreeDmaBufferWithNotification(
  [in] PVOID _context,
  [in] HANDLE Handle,
  [in] PMDL BufferMdl,
  [in] SIZE_T BufferSize
)
{...}