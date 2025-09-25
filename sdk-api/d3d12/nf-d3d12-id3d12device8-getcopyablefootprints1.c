void GetCopyableFootprints1(
  const D3D12_RESOURCE_DESC1         *pResourceDesc,
  UINT                               FirstSubresource,
  UINT                               NumSubresources,
  UINT64                             BaseOffset,
  D3D12_PLACED_SUBRESOURCE_FOOTPRINT *pLayouts,
  UINT                               *pNumRows,
  UINT64                             *pRowSizeInBytes,
  UINT64                             *pTotalBytes
);