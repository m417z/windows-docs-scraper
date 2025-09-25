void GetResourceTiling(
  [in]                ID3D11Resource           *pTiledResource,
  [out, optional]     UINT                     *pNumTilesForEntireResource,
  [out, optional]     D3D11_PACKED_MIP_DESC    *pPackedMipDesc,
  [out, optional]     D3D11_TILE_SHAPE         *pStandardTileShapeForNonPackedMips,
  [in, out, optional] UINT                     *pNumSubresourceTilings,
  [in]                UINT                     FirstSubresourceTilingToGet,
  [out]               D3D11_SUBRESOURCE_TILING *pSubresourceTilingsForNonPackedMips
);