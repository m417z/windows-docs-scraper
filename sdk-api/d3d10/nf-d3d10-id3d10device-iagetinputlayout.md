# ID3D10Device::IAGetInputLayout

## Description

Get a pointer to the input-layout object that is bound to the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

## Parameters

### `ppInputLayout` [out]

Type: **[ID3D10InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10inputlayout)****

A pointer to the input-layout object (see [ID3D10InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10inputlayout)), which describes the input buffers that will be read by the IA stage.

## Remarks

For information about creating an input-layout object, see [Creating the Input-Layout Object](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started).

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)