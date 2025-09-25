typedef struct AE_CURRENT_POSITION {
  UINT64            u64DevicePosition;
  UINT64            u64StreamPosition;
  UINT64            u64PaddingFrames;
  HNSTIME           hnsQPCPosition;
  FLOAT32           f32FramesPerSecond;
  AE_POSITION_FLAGS Flag;
} AE_CURRENT_POSITION, *PAE_CURRENT_POSITION;