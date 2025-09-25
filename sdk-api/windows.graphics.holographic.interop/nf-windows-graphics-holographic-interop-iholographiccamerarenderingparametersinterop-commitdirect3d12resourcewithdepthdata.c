HRESULT CommitDirect3D12ResourceWithDepthData(
  ID3D12Resource *pColorResourceToCommit,
  ID3D12Fence    *pColorResourceFence,
  UINT64         colorResourceFenceSignalValue,
  ID3D12Resource *pDepthResourceToCommit,
  ID3D12Fence    *pDepthResourceFence,
  UINT64         depthResourceFenceSignalValue
);