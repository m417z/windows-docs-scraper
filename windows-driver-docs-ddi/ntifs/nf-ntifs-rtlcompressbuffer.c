NT_RTL_COMPRESS_API NTSTATUS RtlCompressBuffer(
  [in]  USHORT CompressionFormatAndEngine,
  [in]  PUCHAR UncompressedBuffer,
  [in]  ULONG  UncompressedBufferSize,
  [out] PUCHAR CompressedBuffer,
  [in]  ULONG  CompressedBufferSize,
  [in]  ULONG  UncompressedChunkSize,
  [out] PULONG FinalCompressedSize,
  [in]  PVOID  WorkSpace
);