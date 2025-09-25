# ID3D11DeviceContext::IAGetInputLayout

## Description

Get a pointer to the input-layout object that is bound to the input-assembler stage.

## Parameters

### `ppInputLayout` [out]

Type: **[ID3D11InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11inputlayout)****

A pointer to the input-layout object (see [ID3D11InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11inputlayout)), which describes the input buffers that will be read by the IA stage.

## Remarks

For information about creating an input-layout object, see Creating the Input-Layout Object.

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)