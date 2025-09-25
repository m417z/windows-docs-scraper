NT_RTL_COMPRESS_API NTSTATUS RtlDecompressFragment(
  [in]  USHORT CompressionFormat,
  [out] PUCHAR UncompressedFragment,
  [in]  ULONG  UncompressedFragmentSize,
  [in]  PUCHAR CompressedBuffer,
  [in]  ULONG  CompressedBufferSize,
  [in]  ULONG  FragmentOffset,
  [out] PULONG FinalUncompressedSize,
  [in]  PVOID  WorkSpace
);