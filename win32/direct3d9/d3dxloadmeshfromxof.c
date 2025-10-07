HRESULT D3DXLoadMeshFromXof(
  _In_    LPD3DXFILEDATA    pxofMesh,
  _Out_   DWORD             Options,
  _In_    LPDIRECT3DDEVICE9 pDevice,
  _Out_   LPD3DXBUFFER      *ppAdjacency,
  _Inout_ LPD3DXBUFFER      *ppMaterials,
  _Out_   LPD3DXBUFFER      *ppEffectInstances,
  _Inout_ DWORD             *pNumMaterials,
  _Out_   LPD3DXMESH        *ppMesh
);