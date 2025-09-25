typedef struct D3D12_EXISTING_COLLECTION_DESC {
  ID3D12StateObject       *pExistingCollection;
  UINT                    NumExports;
  const D3D12_EXPORT_DESC *pExports;
} D3D12_EXISTING_COLLECTION_DESC;