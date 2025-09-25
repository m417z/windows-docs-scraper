HRESULT CreateLookupTable3D(
        D2D1_BUFFER_PRECISION precision,
  [in]  const UINT32          *extents,
  [in]  const BYTE            *data,
        UINT32                dataCount,
  [in]  const UINT32          *strides,
  [out] ID2D1LookupTable3D    **lookupTable
);