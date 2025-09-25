NT_RTL_COMPRESS_API NTSTATUS RtlDecompressBufferEx2(
  [in]           USHORT CompressionFormat,
  [out]          PUCHAR UncompressedBuffer,
  [in]           ULONG  UncompressedBufferSize,
  [in]           PUCHAR CompressedBuffer,
  [in]           ULONG  CompressedBufferSize,
  [in]           ULONG  UncompressedChunkSize,
  [out]          PULONG FinalUncompressedSize,
  [in, optional] PVOID  WorkSpace
);