PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE PfnD3d12SerializeVersionedRootSignature;

HRESULT PfnD3d12SerializeVersionedRootSignature(
  const D3D12_VERSIONED_ROOT_SIGNATURE_DESC *pRootSignature,
  ID3DBlob **ppBlob,
  ID3DBlob **ppErrorBlob
)
{...}