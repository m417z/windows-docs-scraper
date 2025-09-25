# ID3D11DeviceContext::IASetIndexBuffer

## Description

Bind an index buffer to the input-assembler stage.

## Parameters

### `pIndexBuffer` [in, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)***

A pointer to an [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer) object, that contains indices. The index buffer must have been created with
the [D3D11_BIND_INDEX_BUFFER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) that specifies the format of the data in the index buffer. The only formats allowed for index
buffer data are 16-bit (DXGI_FORMAT_R16_UINT) and 32-bit (DXGI_FORMAT_R32_UINT) integers.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset (in bytes) from the start of the index buffer to the first index to use.

## Remarks

For information about creating index buffers, see [How to: Create an Index Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-buffers-index-how-to).

Calling this method using a buffer that is currently bound for writing (i.e. bound to the stream output pipeline stage) will effectively bind
**NULL** instead because a buffer cannot be bound as both an input and an output at the same time.

The debug layer will generate a warning whenever a resource is prevented from being bound simultaneously as an input and an output, but this will
not prevent invalid data from being used by the runtime.

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)