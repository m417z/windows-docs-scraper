NTSYSAPI NTSTATUS RtlDescribeChunk(
  USHORT CompressionFormat,
  PUCHAR *CompressedBuffer,
  PUCHAR EndOfCompressedBufferPlus1,
  PUCHAR *ChunkBuffer,
  PULONG ChunkSize
);