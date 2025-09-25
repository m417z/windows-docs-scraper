HRESULT CommitDirect3D12Resource(
  ID3D12Resource *pColorResourceToCommit,
  ID3D12Fence    *pColorResourceFence,
  UINT64         colorResourceFenceSignalValue
);