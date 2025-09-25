HRESULT CreateCommandSignature(
  [in]            const D3D12_COMMAND_SIGNATURE_DESC *pDesc,
  [in, optional]  ID3D12RootSignature                *pRootSignature,
                  REFIID                             riid,
  [out, optional] void                               **ppvCommandSignature
);