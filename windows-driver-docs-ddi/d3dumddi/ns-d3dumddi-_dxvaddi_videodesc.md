# _DXVADDI_VIDEODESC structure

## Description

The DXVADDI_VIDEODESC structure describes a video stream.

## Members

### `SampleWidth` [in]

The width of the video sample, in pixels.

### `SampleHeight` [in]

The height of the video sample, in pixels.

### `SampleFormat` [in]

A [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure that describes the extended format of the video sample.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) structure that describes the extended format of the video sample.

### `InputSampleFreq` [in]

A [DXVADDI_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_frequency) structure that defines the frequency of incoming video.

### `OutputFrameFreq` [in]

A DXVADDI_FREQUENCY structure that defines the frame rate of output video.

### `UABProtectionLevel` [in]

A UINT value that specifies the level of data protection that is required when the user accessible bus is present.

### `Reserved` [in]

Reserved. Do not use this member.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)

[DXVADDI_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_frequency)