PALLOCATE_DMA_BUFFER_WITH_NOTIFICATION PallocateDmaBufferWithNotification;

NTSTATUS PallocateDmaBufferWithNotification(
  [in]  PVOID _context,
  [in]  HANDLE Handle,
  [in]  ULONG NotificationCount,
  [in]  SIZE_T RequestedBufferSize,
  [out] PMDL *BufferMdl,
  [out] PSIZE_T AllocatedBufferSize,
        PSIZE_T OffsetFromFirstPage,
  [out] PUCHAR StreamId,
  [out] PULONG FifoSize
)
{...}