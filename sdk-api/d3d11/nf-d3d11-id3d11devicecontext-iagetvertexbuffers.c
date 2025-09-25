void IAGetVertexBuffers(
  [in]            UINT         StartSlot,
  [in]            UINT         NumBuffers,
  [out, optional] ID3D11Buffer **ppVertexBuffers,
  [out, optional] UINT         *pStrides,
  [out, optional] UINT         *pOffsets
);