struct CD3DX12_ROOT_CONSTANTS  : public D3D12_ROOT_CONSTANTS{
       CD3DX12_ROOT_CONSTANTS();
       explicit CD3DX12_ROOT_CONSTANTS(const D3D12_ROOT_CONSTANTS &o);
       CD3DX12_ROOT_CONSTANTS(UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0);
  void inline Init(UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0);
  void static inline Init(D3D12_ROOT_CONSTANTS &rootConstants, UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0);
};