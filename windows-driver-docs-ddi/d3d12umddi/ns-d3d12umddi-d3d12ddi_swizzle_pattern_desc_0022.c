typedef struct D3D12DDI_SWIZZLE_PATTERN_DESC_0022 {
  D3D12DDI_SWIZZLE_BIT_ENTRY     InterleavePatternSourceBits[32];
  D3D12DDI_SWIZZLE_BIT_ENTRY     InterleavePatternXORSourceBits[32];
  D3D12DDI_SWIZZLE_BIT_ENTRY     InterleavePatternXOR2SourceBits[32];
  D3D12DDI_SWIZZLE_BIT_ENTRY     InterleavePatternXOR3SourceBits[32];
  D3D12DDI_SWIZZLE_BIT_ENTRY     InterleavePatternXOR4SourceBits[32];
  D3D12DDI_SWIZZLE_BIT_ENTRY     PostambleXORSourceBits[32];
  D3D12DDI_SWIZZLE_BIT_ENTRY     PostambleXOR2SourceBits[32];
  UINT                           PostambleXORImmediate;
  D3D12DDI_SWIZZLE_PATTERN_FLAGS Flags;
} D3D12DDI_SWIZZLE_PATTERN_DESC_0022;