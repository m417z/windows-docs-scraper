# ID3D11DeviceContext::IAGetIndexBuffer

## Description

Get a pointer to the index buffer that is bound to the input-assembler stage.

## Parameters

### `pIndexBuffer` [out, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)****

A pointer to an index buffer returned by the method (see [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)).

### `Format` [out, optional]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)***

Specifies format of the data in the index buffer (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)). These formats provide the size and type of
the data in the buffer. The only formats allowed for index buffer data are 16-bit (DXGI_FORMAT_R16_UINT) and 32-bit (DXGI_FORMAT_R32_UINT)
integers.

### `Offset` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Offset (in bytes) from the start of the index buffer, to the first index to use.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces
when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)