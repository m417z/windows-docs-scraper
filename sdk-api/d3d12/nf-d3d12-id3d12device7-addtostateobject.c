HRESULT AddToStateObject(
  const D3D12_STATE_OBJECT_DESC *pAddition,
  ID3D12StateObject             *pStateObjectToGrowFrom,
  REFIID                        riid,
  void                          **ppNewStateObject
);