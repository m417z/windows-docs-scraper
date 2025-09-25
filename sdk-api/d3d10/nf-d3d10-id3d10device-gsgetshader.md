# ID3D10Device::GSGetShader

## Description

Get the geometry shader currently set on the device.

## Parameters

### `ppGeometryShader` [out]

Type: **[ID3D10GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10geometryshader)****

Address of a pointer to a geometry shader (see [ID3D10GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10geometryshader)) to be returned by the method.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)