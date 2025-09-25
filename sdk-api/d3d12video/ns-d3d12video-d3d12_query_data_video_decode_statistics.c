typedef struct D3D12_QUERY_DATA_VIDEO_DECODE_STATISTICS {
  UINT64        Status;
  UINT64        NumMacroblocksAffected;
  DXGI_RATIONAL FrameRate;
  UINT          BitRate;
} D3D12_QUERY_DATA_VIDEO_DECODE_STATISTICS;