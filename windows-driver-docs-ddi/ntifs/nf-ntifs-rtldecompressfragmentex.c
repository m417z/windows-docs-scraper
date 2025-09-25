NT_RTL_COMPRESS_API NTSTATUS RtlDecompressFragmentEx(
  [in]  USHORT CompressionFormat,
  [out] PUCHAR UncompressedFragment,
  [in]  ULONG  UncompressedFragmentSize,
  [in]  PUCHAR CompressedBuffer,
  [in]  ULONG  CompressedBufferSize,
  [in]  ULONG  FragmentOffset,
  [in]  ULONG  UncompressedChunkSize,
  [out] PULONG FinalUncompressedSize,
  [in]  PVOID  WorkSpace
);