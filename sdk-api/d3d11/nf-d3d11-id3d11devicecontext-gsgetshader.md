# ID3D11DeviceContext::GSGetShader

## Description

Get the geometry shader currently set on the device.

## Parameters

### `ppGeometryShader` [out]

Type: **[ID3D11GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11geometryshader)****

Address of a pointer to a geometry shader (see [ID3D11GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11geometryshader)) to be returned by the method.

### `ppClassInstances` [out, optional]

Type: **[ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)****

Pointer to an array of class instance interfaces (see [ID3D11ClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classinstance)).

### `pNumClassInstances` [in, out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The number of class-instance elements in the array.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)