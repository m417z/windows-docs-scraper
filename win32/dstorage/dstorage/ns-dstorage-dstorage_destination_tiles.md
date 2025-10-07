# DSTORAGE_DESTINATION_TILES structure (dstorage.h)

Describes the destination for a request with [DSTORAGE_REQUEST_OPTIONS::DestinationType](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_request_options) set to [DSTORAGE_REQUEST_DESTINATION_TILES](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_destination_type).

## Members

`Resource`

Address of the resource to receive the final result of this request. The source buffer is expected to contain data arranged as if it were the source to a [CopyTiles](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytiles) call with these parameters.

`TiledRegionStartCoordinate`

The starting coordinates of the tiled region.

`TileRegionSize`

The size of the tiled region.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |