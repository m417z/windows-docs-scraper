# ID3D10Device::PSSetShader

## Description

Sets a pixel shader to the device.

## Parameters

### `pPixelShader` [in]

Type: **[ID3D10PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10pixelshader)***

Pointer to a pixel shader (see [ID3D10PixelShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10pixelshader)). Passing in **NULL** disables the shader for this pipeline stage.

## Remarks

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)