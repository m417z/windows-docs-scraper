NT_RTL_COMPRESS_API NTSTATUS RtlDecompressBufferEx(
  [in]  USHORT CompressionFormat,
  [out] PUCHAR UncompressedBuffer,
  [in]  ULONG  UncompressedBufferSize,
  [in]  PUCHAR CompressedBuffer,
  [in]  ULONG  CompressedBufferSize,
  [out] PULONG FinalUncompressedSize,
  [in]  PVOID  WorkSpace
);