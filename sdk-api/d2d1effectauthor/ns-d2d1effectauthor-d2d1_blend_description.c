typedef struct D2D1_BLEND_DESCRIPTION {
  D2D1_BLEND           sourceBlend;
  D2D1_BLEND           destinationBlend;
  D2D1_BLEND_OPERATION blendOperation;
  D2D1_BLEND           sourceBlendAlpha;
  D2D1_BLEND           destinationBlendAlpha;
  D2D1_BLEND_OPERATION blendOperationAlpha;
  FLOAT                blendFactor[4];
} D2D1_BLEND_DESCRIPTION;