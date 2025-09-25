PFN_D3D12_SERIALIZE_ROOT_SIGNATURE PfnD3d12SerializeRootSignature;

HRESULT PfnD3d12SerializeRootSignature(
  const D3D12_ROOT_SIGNATURE_DESC *pRootSignature,
  D3D_ROOT_SIGNATURE_VERSION Version,
  ID3DBlob **ppBlob,
  ID3DBlob **ppErrorBlob
)
{...}