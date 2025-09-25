# D3D11_VIDEO_PROCESSOR_CUSTOM_RATE structure

## Description

Specifies a custom rate for frame-rate conversion or inverse telecine (IVTC).

## Members

### `CustomRate`

The ratio of the output frame rate to the input frame rate, expressed as a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that holds a rational number.

### `OutputFrames`

The number of output frames that will be generated for every *N* input samples, where *N* = **InputFramesOrFields**.

### `InputInterlaced`

If **TRUE**, the input stream must be interlaced. Otherwise, the input stream must be progressive.

### `InputFramesOrFields`

The number of input fields or frames for every *N* output frames that will be generated, where *N* = **OutputFrames**.

## Remarks

The **CustomRate** member gives the rate conversion factor, while the remaining members define the pattern of input and output samples.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoProcessorEnumerator::GetVideoProcessorCustomRate](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcustomrate)