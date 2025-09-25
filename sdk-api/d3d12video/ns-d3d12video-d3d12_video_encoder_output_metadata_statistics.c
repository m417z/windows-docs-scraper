typedef struct D3D12_VIDEO_ENCODER_OUTPUT_METADATA_STATISTICS {
  UINT64 AverageQP;
  UINT64 IntraCodingUnitsCount;
  UINT64 InterCodingUnitsCount;
  UINT64 SkipCodingUnitsCount;
  UINT64 AverageMotionEstimationXDirection;
  UINT64 AverageMotionEstimationYDirection;
} D3D12_VIDEO_ENCODER_OUTPUT_METADATA_STATISTICS;