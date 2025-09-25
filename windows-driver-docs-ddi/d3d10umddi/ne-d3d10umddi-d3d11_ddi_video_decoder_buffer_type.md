# D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE enumeration

## Description

The **D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE** enumeration indicates the type of buffer used by a D3D11 video decoder.

## Constants

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_UNKNOWN:0`

An unknown buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_PICTURE_PARAMETERS:1`

Picture parameters decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_MACROBLOCK_CONTROL:2`

Macroblock control command decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_RESIDUAL_DIFFERENCE:3`

Residual block difference decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_DEBLOCKING_CONTROL:4`

Deblocking filter control command decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_INVERSE_QUANTIZATION_MATRIX:5`

Inverse-quantization matrix decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_SLICE_CONTROL:6`

Slice-control decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_BITSTREAM:7`

Bitstream data decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_MOTION_VECTOR:8`

Motion-vector decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_FILM_GRAIN:9`

Film-grain decode compressed buffer format.

### `D3D11_1DDI_VIDEO_DECODER_BUFFER_HUFFMAN_TABLE:10`

The buffer format is Huffman tables.

## Remarks

Note that the **D3D11_DDI_VIDEO_DECODER_BUFFER_TYPE** and **D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE** enumerations are defined as the same type.

## See also

[**D3D11DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)