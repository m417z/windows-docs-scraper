float * XMConvertHalfToFloatStream(
  [out] float      *pOutputStream,
  [in]  size_t     OutputStride,
  [in]  const HALF *pInputStream,
  [in]  size_t     InputStride,
  [in]  size_t     HalfCount
) noexcept;