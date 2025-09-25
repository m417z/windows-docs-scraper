BOOL Compress(
  [in]  COMPRESSOR_HANDLE CompressorHandle,
  [in]  LPCVOID           UncompressedData,
  [in]  SIZE_T            UncompressedDataSize,
  [out] PVOID             CompressedBuffer,
  [in]  SIZE_T            CompressedBufferSize,
  [out] PSIZE_T           CompressedDataSize
);