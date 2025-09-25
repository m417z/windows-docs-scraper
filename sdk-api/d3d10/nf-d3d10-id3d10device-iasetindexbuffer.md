# ID3D10Device::IASetIndexBuffer

## Description

Bind an [index buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to the [input-assembler](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage) stage.

## Parameters

### `pIndexBuffer` [in]

Type: **[ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)***

A pointer to a buffer (see [ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)) that contains indices. The index buffer must have been created with the [D3D10_BIND_INDEX_BUFFER](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) flag.

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

Specifies format of the data in the index buffer. The only formats allowed for index buffer data are 16-bit ([DXGI_FORMAT_R16_UINT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)) and 32-bit (**DXGI_FORMAT_R32_UINT**) integers.

### `Offset` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset (in bytes) from the start of the index buffer to the first index to use.

## Remarks

For information about creating index buffers, see [Create an Index Buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-creating).

Calling this method using a buffer that is currently bound for writing (i.e. bound to the [stream output](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-stream-stage) pipeline stage) will effectively bind **NULL** instead because a buffer cannot be bound as both an input and an output at the same time.

The [Debug Layer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-api-features-layers) will generate a warning whenever a resource is prevented from being bound simultaneously as an input and an output, but this will not prevent invalid data from being used by the runtime.

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)