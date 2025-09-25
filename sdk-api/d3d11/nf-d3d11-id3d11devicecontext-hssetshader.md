# ID3D11DeviceContext::HSSetShader

## Description

Set a hull shader to the device.

## Parameters

### `pHullShader` [in, optional]

Type: **[ID3D11HullShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11hullshader)***

Pointer to a hull shader (see [ID3D11HullShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11hullshader)). Passing in **NULL** disables the shader for this pipeline stage.

### `ppClassInstances` [in, optional]

Type: **[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)***

A pointer to an array of class-instance interfaces (see [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)). Each interface used by a shader must have a corresponding class instance or the shader will get disabled. Set ppClassInstances to **NULL** if the shader does not use any interfaces.

### `NumClassInstances`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of class-instance interfaces in the array.

## Remarks

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

The maximum number of instances a shader can have is 256.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)