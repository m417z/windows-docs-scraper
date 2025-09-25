# D2D1_BUFFER_PRECISION enumeration

## Description

Represents the bit depth of the imaging pipeline in Direct2D.

## Constants

### `D2D1_BUFFER_PRECISION_UNKNOWN:0`

The buffer precision is not specified.

### `D2D1_BUFFER_PRECISION_8BPC_UNORM:1`

Use 8-bit normalized integer per channel.

### `D2D1_BUFFER_PRECISION_8BPC_UNORM_SRGB:2`

Use 8-bit normalized integer standard RGB data per channel.

### `D2D1_BUFFER_PRECISION_16BPC_UNORM:3`

Use 16-bit normalized integer per channel.

### `D2D1_BUFFER_PRECISION_16BPC_FLOAT:4`

Use 16-bit floats per channel.

### `D2D1_BUFFER_PRECISION_32BPC_FLOAT:5`

Use 32-bit floats per channel.

### `D2D1_BUFFER_PRECISION_FORCE_DWORD:0xffffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits.

Do not use this value.

## Remarks

**Note** Feature level 9 may or may not support precision types other than 8BPC.

## See also

[D2D1_RENDERING_CONTROLS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_rendering_controls)

[ID2D1DeviceContext::GetRenderingControls](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getrenderingcontrols)

[ID2D1DeviceContext::SetRenderingControls](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setrenderingcontrols(constd2d1_rendering_controls_))