HRESULT GetPatterns(
  [in]      REFGUID            guidContainerFormat,
  [in]      UINT               cbSize,
  [in, out] WICMetadataPattern *pPattern,
  [in, out] UINT               *pcCount,
  [in, out] UINT               *pcbActual
);