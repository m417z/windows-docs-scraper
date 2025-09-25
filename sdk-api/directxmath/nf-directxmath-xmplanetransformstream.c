XMFLOAT4 *XM_CALLCONV XMPlaneTransformStream(
  [out] XMFLOAT4       *pOutputStream,
  [in]  size_t         OutputStride,
  [in]  const XMFLOAT4 *pInputStream,
  [in]  size_t         InputStride,
  [in]  size_t         PlaneCount,
        FXMMATRIX      ITM
) noexcept;