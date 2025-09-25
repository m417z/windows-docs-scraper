# D3D11_PIXEL_SHADER_TRACE_DESC structure

## Description

Describes an instance of a pixel shader to trace.

## Members

### `Invocation`

The invocation number of the instance of the pixel shader.

### `X`

The x-coordinate of the pixel.

### `Y`

The y-coordinate of the pixel.

### `SampleMask`

A value that describes a mask of pixel samples to trace. If this value specifies any of the masked samples, the trace is activated. The least significant bit (LSB) is sample 0. The non-multisample antialiasing (MSAA) counts as a sample count of 1; therefore, the LSB of **SampleMask** should be set. If set to zero, the pixel is not traced. However, pixel traces can still be enabled on an invocation basis.

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)