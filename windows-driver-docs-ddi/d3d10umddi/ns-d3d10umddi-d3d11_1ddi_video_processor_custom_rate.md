# D3D11_1DDI_VIDEO_PROCESSOR_CUSTOM_RATE structure

## Description

Specifies a custom rate for frame-rate conversion or inverse telecine (IVTC).

## Members

### `CustomRate`

The ratio of the output frame rate to the input frame rate, expressed as a [**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that holds a rational number.

### `OutputFrames`

The number of output frames that will be generated for every *N* input samples, where *N* = **InputFramesOrFields**.

### `InputInterlaced`

If **TRUE**, the input stream must be interlaced. Otherwise, the input stream must be progressive.

### `InputFramesOrFields`

The number of input fields or frames for every *N* output frames that will be generated, where *N* = **OutputFrames**.

## Remarks

The **CustomRate** member gives the rate conversion factor, while the remaining members define the pattern of input and output samples.

## See also

[**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational)