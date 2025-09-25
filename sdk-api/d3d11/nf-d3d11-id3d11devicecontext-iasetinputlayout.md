# ID3D11DeviceContext::IASetInputLayout

## Description

Bind an input-layout object to the input-assembler stage.

## Parameters

### `pInputLayout` [in, optional]

Type: **[ID3D11InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11inputlayout)***

A pointer to the input-layout object (see [ID3D11InputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11inputlayout)), which describes the input buffers that will be read by the IA stage.

## Remarks

Input-layout objects describe how vertex buffer data is streamed into the IA pipeline stage. To create an input-layout object, call [ID3D11Device::CreateInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createinputlayout).

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)