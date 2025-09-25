PALLOCATE_DMA_BUFFER PallocateDmaBuffer;

NTSTATUS PallocateDmaBuffer(
  [in]  PVOID _context,
  [in]  HANDLE Handle,
  [in]  SIZE_T RequestedBufferSize,
  [out] PMDL *BufferMdl,
  [out] PSIZE_T AllocatedBufferSize,
  [out] PUCHAR StreamId,
  [out] PULONG FifoSize
)
{...}