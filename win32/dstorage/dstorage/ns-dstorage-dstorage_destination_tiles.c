struct DSTORAGE_DESTINATION_TILES {
  ID3D12Resource                  *Resource;
  D3D12_TILED_RESOURCE_COORDINATE TiledRegionStartCoordinate;
  D3D12_TILE_REGION_SIZE          TileRegionSize;
};