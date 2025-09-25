# DXVAHD_CUSTOM_RATE_DATA structure

## Description

Specifies a custom rate for frame-rate conversion or inverse telecine (IVTC).

## Members

### `CustomRate`

The ratio of the output frame rate to the input frame rate, expressed as a [DXVAHD_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_rational) structure that holds a rational number.

### `OutputFrames`

The number of output frames that will be generated for every *N* input samples, where *N* = **InputFramesOrFields**.

### `InputInterlaced`

If **TRUE**, the input stream must be interlaced. Otherwise, the input stream must be progressive.

### `InputFramesOrFields`

The number of input fields or frames for every *N* output frames that will be generated, where *N* = **OutputFrames**.

## Remarks

The **CustomRate** member gives the rate conversion factor, while the remaining members define the pattern of input and output samples.

Here are some example uses for this structure:

* Frame rate conversion from 60p to 120p (doubling the frame rate).

  + **CustomRate**: 2/1
  + **OutputFrames**: 2
  + **InputInterlaced**: **FALSE**
  + **InputFramesOrFields**: 1
* Reverse 2:3 pulldown (IVTC) from 60i to 24p.

  + **CustomRate**: 4/5
  + **OutputFrames**: 4
  + **InputInterlaced**: **TRUE**
  + **InputFramesOrFields**: 10(Ten interlaced fields are converted into four progressive frames.)

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)