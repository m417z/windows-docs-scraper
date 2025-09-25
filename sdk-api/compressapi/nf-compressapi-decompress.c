BOOL Decompress(
  [in]  DECOMPRESSOR_HANDLE DecompressorHandle,
  [in]  LPCVOID             CompressedData,
  [in]  SIZE_T              CompressedDataSize,
  [out] PVOID               UncompressedBuffer,
  [in]  SIZE_T              UncompressedBufferSize,
  [out] PSIZE_T             UncompressedDataSize
);