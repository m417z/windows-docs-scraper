# ID3D10Device::IAGetPrimitiveTopology

## Description

Get information about the [primitive type](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-primitive-topologies), and data order that describes input data for the [input assembler](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage) stage.

## Parameters

### `pTopology` [out]

Type: **[D3D10_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb205334(v=vs.85))***

A pointer to the type of primitive, and ordering of the primitive data (see [D3D10_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb205334(v=vs.85))).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)