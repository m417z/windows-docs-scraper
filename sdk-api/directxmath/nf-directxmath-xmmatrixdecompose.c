bool XM_CALLCONV XMMatrixDecompose(
  [in, out] XMVECTOR  *outScale,
  [in, out] XMVECTOR  *outRotQuat,
  [in, out] XMVECTOR  *outTrans,
  [in]      FXMMATRIX M
) noexcept;