# ID3D10Device::IAGetIndexBuffer

## Description

Get a pointer to the [index buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) that is bound to the [input-assembler](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage) stage.

## Parameters

### `pIndexBuffer` [out]

Type: **[ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)****

A pointer to an index buffer returned by the method (see [ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)).

### `Format` [out]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)***

Specifies format of the data in the index buffer (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)). These formats provide the size and type of the data in the buffer. The only formats allowed for index buffer data are 16-bit (DXGI_FORMAT_R16_UINT) and 32-bit (DXGI_FORMAT_R32_UINT) integers.

### `Offset` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Offset (in bytes) from the start of the index buffer, to the first index to use.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)