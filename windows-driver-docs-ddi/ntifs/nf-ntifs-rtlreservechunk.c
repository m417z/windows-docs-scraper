NTSYSAPI NTSTATUS RtlReserveChunk(
  USHORT CompressionFormat,
  PUCHAR *CompressedBuffer,
  PUCHAR EndOfCompressedBufferPlus1,
  PUCHAR *ChunkBuffer,
  ULONG  ChunkSize
);