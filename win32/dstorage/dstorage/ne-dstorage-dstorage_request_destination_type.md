# DSTORAGE_REQUEST_DESTINATION_TYPE enumeration (dstorage.h)

Defines constants that specify the destination type of a DirectStorage request.

## Constants

|   |
| ---- |
| **DSTORAGE_REQUEST_DESTINATION_MEMORY** <br> Specifies that the destination of the DirectStorage request is a block of memory. |
| **DSTORAGE_REQUEST_DESTINATION_BUFFER** <br> Specifies that the destination of the DirectStorage request is an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) that is a buffer.|
| **DSTORAGE_REQUEST_DESTINATION_TEXTURE_REGION** <br> Specifies that the destination of the DirectStorage request is an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) that is a texture.|
| **DSTORAGE_REQUEST_DESTINATION_MULTIPLE_SUBRESOURCES** <br> Specifies that the destination of the DirectStorage request is an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) that is a texture that will receive all subresources in a single request.|
| **DSTORAGE_REQUEST_DESTINATION_TILES** <br> Specifies that the destination of the DirectStorage request is an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) that is tiled.|
| **DSTORAGE_REQUEST_DESTINATION_MULTIPLE_SUBRESOURCES_RANGE** <br> Specifies that the destination of the DirectStorage request is an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) that is a texture that will receive the number of subresources specified in a single request.|

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |