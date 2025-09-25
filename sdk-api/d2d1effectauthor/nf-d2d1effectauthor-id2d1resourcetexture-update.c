HRESULT Update(
  [in, optional] const UINT32 *minimumExtents,
  [in, optional] const UINT32 *maximimumExtents,
  [in]           const UINT32 *strides,
                 UINT32       dimensions,
  [in]           const BYTE   *data,
                 UINT32       dataCount
);