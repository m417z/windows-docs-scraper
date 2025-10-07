struct CD3DX12_VIEWPORT  : public D3D12_VIEWPORT{
   CD3DX12_VIEWPORT();
   explicit CD3DX12_VIEWPORT(const D3D12_VIEWPORT& o);
   explicit CD3DX12_VIEWPORT(FLOAT topLeftX, FLOAT topLeftY, FLOAT width, FLOAT height, FLOAT minDepth = D3D12_MIN_DEPTH, FLOAT maxDepth = D3D12_MAX_DEPTH);
   explicit CD3DX12_VIEWPORT(ID3D12Resource* pResource, UINT mipSlice = 0, FLOAT topLeftX = 0.0f, FLOAT topLeftY = 0.0f, FLOAT minDepth = D3D12_MIN_DEPTH, FLOAT maxDepth = D3D12_MAX_DEPTH);
   ~CD3DX12_VIEWPORT();
   operator const D3D12_VIEWPORT&() const;
};