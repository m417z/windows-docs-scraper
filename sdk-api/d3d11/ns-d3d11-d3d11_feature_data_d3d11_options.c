typedef struct D3D11_FEATURE_DATA_D3D11_OPTIONS {
  BOOL OutputMergerLogicOp;
  BOOL UAVOnlyRenderingForcedSampleCount;
  BOOL DiscardAPIsSeenByDriver;
  BOOL FlagsForUpdateAndCopySeenByDriver;
  BOOL ClearView;
  BOOL CopyWithOverlap;
  BOOL ConstantBufferPartialUpdate;
  BOOL ConstantBufferOffsetting;
  BOOL MapNoOverwriteOnDynamicConstantBuffer;
  BOOL MapNoOverwriteOnDynamicBufferSRV;
  BOOL MultisampleRTVWithForcedSampleCountOne;
  BOOL SAD4ShaderInstructions;
  BOOL ExtendedDoublesShaderInstructions;
  BOOL ExtendedResourceSharing;
} D3D11_FEATURE_DATA_D3D11_OPTIONS;