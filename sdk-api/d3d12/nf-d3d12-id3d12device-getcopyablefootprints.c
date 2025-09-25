void GetCopyableFootprints(
  [in]            const D3D12_RESOURCE_DESC          *pResourceDesc,
  [in]            UINT                               FirstSubresource,
  [in]            UINT                               NumSubresources,
                  UINT64                             BaseOffset,
  [out, optional] D3D12_PLACED_SUBRESOURCE_FOOTPRINT *pLayouts,
  [out, optional] UINT                               *pNumRows,
  [out, optional] UINT64                             *pRowSizeInBytes,
  [out, optional] UINT64                             *pTotalBytes
);