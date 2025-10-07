typedef struct D3DXMESHCONTAINER {
  LPSTR                Name;
  D3DXMESHDATA         MeshData;
  LPD3DXMATERIAL       pMaterials;
  LPD3DXEFFECTINSTANCE pEffects;
  DWORD                NumMaterials;
  DWORD                *pAdjacency;
  LPD3DXSKININFO       pSkinInfo;
  D3DXMESHCONTAINER    *pNextMeshContainer;
} D3DXMESHCONTAINER, *LPD3DXMESHCONTAINER;