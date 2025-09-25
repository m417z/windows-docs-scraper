# ID3D11DeviceContext::PSGetShader

## Description

Get the pixel shader currently set on the device.

## Parameters

### `ppPixelShader` [out]

Type: **[ID3D11PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11pixelshader)****

Address of a pointer to a pixel shader (see [ID3D11PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11pixelshader)) to be returned by the method.

### `ppClassInstances` [out, optional]

Type: **[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)****

Pointer to an array of class instance interfaces (see [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)).

### `pNumClassInstances` [in, out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The number of class-instance elements in the array.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed, to avoid memory leaks.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)