HRESULT D3D12SerializeVersionedRootSignature(
  [in]            const D3D12_VERSIONED_ROOT_SIGNATURE_DESC *pRootSignature,
  [out]           ID3DBlob                                  **ppBlob,
  [out, optional] ID3DBlob                                  **ppErrorBlob
);