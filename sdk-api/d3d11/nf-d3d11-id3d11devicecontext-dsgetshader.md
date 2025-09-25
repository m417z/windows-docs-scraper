# ID3D11DeviceContext::DSGetShader

## Description

Get the domain shader currently set on the device.

## Parameters

### `ppDomainShader` [out]

Type: **[ID3D11DomainShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11domainshader)****

Address of a pointer to a domain shader (see [ID3D11DomainShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11domainshader)) to be returned by the method.

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