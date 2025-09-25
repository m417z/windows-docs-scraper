NTSYSAPI NTSTATUS RtlCompressChunks(
  PUCHAR                UncompressedBuffer,
  ULONG                 UncompressedBufferSize,
  PUCHAR                CompressedBuffer,
  ULONG                 CompressedBufferSize,
  PCOMPRESSED_DATA_INFO CompressedDataInfo,
  ULONG                 CompressedDataInfoLength,
  PVOID                 WorkSpace
);