XMFLOAT2 *XM_CALLCONV XMVector2TransformNormalStream(
  [out] XMFLOAT2       *pOutputStream,
  [in]  size_t         OutputStride,
  [in]  const XMFLOAT2 *pInputStream,
  [in]  size_t         InputStride,
  [in]  size_t         VectorCount,
  [in]  FXMMATRIX      M
) noexcept;