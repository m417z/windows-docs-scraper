typedef struct _D3D10_EFFECT_DESC {
  BOOL IsChildEffect;
  UINT ConstantBuffers;
  UINT SharedConstantBuffers;
  UINT GlobalVariables;
  UINT SharedGlobalVariables;
  UINT Techniques;
} D3D10_EFFECT_DESC;