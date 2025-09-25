NT_RTL_COMPRESS_API NTSTATUS RtlGetCompressionWorkSpaceSize(
  [in]  USHORT CompressionFormatAndEngine,
  [out] PULONG CompressBufferWorkSpaceSize,
  [out] PULONG CompressFragmentWorkSpaceSize
);