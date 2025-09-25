# ID3D10Device::IASetInputLayout

## Description

Bind an input-layout object to the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

## Parameters

### `pInputLayout` [in]

Type: **[ID3D10InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10inputlayout)***

A pointer to the input-layout object (see [ID3D10InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10inputlayout)), which describes the input buffers that will be read by the IA stage.

## Remarks

Input-layout objects describe how vertex buffer data is streamed into the IA pipeline stage. To create an input-layout object, call [ID3D10Device::CreateInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createinputlayout).

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)