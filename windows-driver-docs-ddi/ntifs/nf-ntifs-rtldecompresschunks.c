NTSYSAPI NTSTATUS RtlDecompressChunks(
  PUCHAR                UncompressedBuffer,
  ULONG                 UncompressedBufferSize,
  PUCHAR                CompressedBuffer,
  ULONG                 CompressedBufferSize,
  PUCHAR                CompressedTail,
  ULONG                 CompressedTailSize,
  PCOMPRESSED_DATA_INFO CompressedDataInfo
);