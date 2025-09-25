typedef struct D3DWDDM2_2DDI_SWIZZLE_PATTERN_DESC {
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY InterleavePatternSourceBits[32];
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY InterleavePatternXORSourceBits[32];
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY InterleavePatternXOR2SourceBits[32];
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY InterleavePatternXOR3SourceBits[32];
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY InterleavePatternXOR4SourceBits[32];
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY PostambleXORSourceBits[32];
  D3DWDDM2_0DDI_SWIZZLE_BIT_ENTRY PostambleXOR2SourceBits[32];
  UINT                            PostambleXORImmediate;
  UINT                            Flags;
} D3DWDDM2_2DDI_SWIZZLE_PATTERN_DESC;