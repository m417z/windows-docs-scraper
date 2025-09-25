PALLOCATE_CONTIGUOUS_DMA_BUFFER PallocateContiguousDmaBuffer;

NTSTATUS PallocateContiguousDmaBuffer(
  [in]  PVOID _context,
  [in]  HANDLE Handle,
        ULONG RequestedBufferSize,
  [out] PVOID *DataBuffer,
  [out] PHDAUDIO_BUFFER_DESCRIPTOR *BdlBuffer
)
{...}