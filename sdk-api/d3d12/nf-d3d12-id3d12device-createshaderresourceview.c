void CreateShaderResourceView(
  [in, optional] ID3D12Resource                        *pResource,
  [in, optional] const D3D12_SHADER_RESOURCE_VIEW_DESC *pDesc,
  [in]           D3D12_CPU_DESCRIPTOR_HANDLE           DestDescriptor
);