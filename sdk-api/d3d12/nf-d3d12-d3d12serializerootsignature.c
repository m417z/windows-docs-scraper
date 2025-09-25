HRESULT D3D12SerializeRootSignature(
  [in]            const D3D12_ROOT_SIGNATURE_DESC *pRootSignature,
  [in]            D3D_ROOT_SIGNATURE_VERSION      Version,
  [out]           ID3DBlob                        **ppBlob,
  [out, optional] ID3DBlob                        **ppErrorBlob
);