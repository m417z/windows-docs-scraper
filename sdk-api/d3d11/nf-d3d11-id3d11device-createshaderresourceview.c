HRESULT CreateShaderResourceView(
  [in]            ID3D11Resource                        *pResource,
  [in, optional]  const D3D11_SHADER_RESOURCE_VIEW_DESC *pDesc,
  [out, optional] ID3D11ShaderResourceView              **ppSRView
);