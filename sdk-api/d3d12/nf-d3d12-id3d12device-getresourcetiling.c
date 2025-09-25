void GetResourceTiling(
  [in]                ID3D12Resource           *pTiledResource,
  [out, optional]     UINT                     *pNumTilesForEntireResource,
  [out, optional]     D3D12_PACKED_MIP_INFO    *pPackedMipDesc,
  [out, optional]     D3D12_TILE_SHAPE         *pStandardTileShapeForNonPackedMips,
  [in, out, optional] UINT                     *pNumSubresourceTilings,
  [in]                UINT                     FirstSubresourceTilingToGet,
  [out]               D3D12_SUBRESOURCE_TILING *pSubresourceTilingsForNonPackedMips
);