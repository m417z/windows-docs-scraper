# ID3D10Device::PSGetShader

## Description

Get the pixel shader currently set on the device.

## Parameters

### `ppPixelShader` [out]

Type: **[ID3D10PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10pixelshader)****

Address of a pointer to a pixel shader (see [ID3D10PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10pixelshader)) to be returned by the method.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)