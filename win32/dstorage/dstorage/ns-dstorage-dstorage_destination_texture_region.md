# DSTORAGE_DESTINATION_TEXTURE_REGION structure (dstorage.h)

Describes the destination for a request with [DSTORAGE_REQUEST_OPTIONS::DestinationType](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_request_options) set to [DSTORAGE_REQUEST_DESTINATION_TEXTURE_REGION](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_destination_type).

## Members

`Resource`

Address of the resource to receive the final result of this request.

`SubresourceIndex`

Describes the destination texture copy location. The subresource referred to must be in the [D3D12_RESOURCE_STATE_COMMON](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) state.

`Region`

Coordinates and size of the destination region to copy, in pixels.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |