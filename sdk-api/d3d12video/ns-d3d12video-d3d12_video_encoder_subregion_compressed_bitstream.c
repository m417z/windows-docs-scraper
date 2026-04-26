typedef struct D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM {
  D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM_BUFFER_MODE BufferMode;
  UINT                                                           ExpectedSubregionCount;
  UINT64                                                         *pSubregionBitstreamsBaseOffsets;
  ID3D12Resource                                                 **ppSubregionBitstreams;
  ID3D12Resource                                                 **ppSubregionSizes;
  ID3D12Resource                                                 **ppSubregionOffsets;
  ID3D12Fence                                                    **ppSubregionFences;
  UINT64                                                         *pSubregionFenceValues;
} D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM;