XMFLOAT3 *XM_CALLCONV XMVector3ProjectStream(
  [out] XMFLOAT3       *pOutputStream,
  [in]  size_t         OutputStride,
  [in]  const XMFLOAT3 *pInputStream,
  [in]  size_t         InputStride,
  [in]  size_t         VectorCount,
  [in]  float          ViewportX,
  [in]  float          ViewportY,
  [in]  float          ViewportWidth,
  [in]  float          ViewportHeight,
  [in]  float          ViewportMinZ,
  [in]  float          ViewportMaxZ,
  [in]  FXMMATRIX      Projection,
  [in]  CXMMATRIX      View,
  [in]  CXMMATRIX      World
) noexcept;