HRESULT D3DXComputeTangentFrameEx(
  _In_        ID3DXMesh   *pMesh,
  _In_        DWORD       dwTextureInSemantic,
  _In_        DWORD       dwTextureInIndex,
  _In_        DWORD       dwUPartialOutSemantic,
  _In_        DWORD       dwUPartialOutIndex,
  _In_        DWORD       dwVPartialOutSemantic,
  _In_        DWORD       dwVPartialOutIndex,
  _In_        DWORD       dwNormalOutSemantic,
  _In_        DWORD       dwNormalOutIndex,
  _In_        DWORD       dwOptions,
  _In_  const DWORD       *pdwAdjacency,
  _In_        FLOAT       fPartialEdgeThreshold,
  _In_        FLOAT       fSingularPointThreshold,
  _In_        FLOAT       fNormalEdgeThreshold,
  _Out_       ID3DXMesh   **ppMeshOut,
  _Out_       ID3DXBuffer **ppVertexMapping
);