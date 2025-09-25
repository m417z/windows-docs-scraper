# _DXVA_VideoDesc structure

## Description

The DXVA_VideoDesc structure is sent by the renderer to the driver to specify a description of the video stream on which the deinterlacing or frame-rate conversion operation is to be performed.

## Members

### `Size`

Specifies the size of this structure, in bytes.

### `SampleWidth`

Specifies the width of the sample, in pixels.

### `SampleHeight`

Specifies the height of the sample, in pixels.

### `SampleFormat`

Specifies the format of the sample defined by the [DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat) structure.

### `d3dFormat`

Specifies the Direct3D surface format of the sample.

### `InputSampleFreq`

Specifies the frequency of incoming video defined by the [DXVA_Frequency](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_frequency) structure.

### `OutputFrameFreq`

Specifies the desired frame rate of output video as defined by [DXVA_Frequency](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_frequency).

## Remarks

For examples showing structure member values for deinterlacing or converting different types of content, see [DeinterlaceQueryAvailableModes](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-deinterlacecontainerdeviceclass-deinterlacequeryavailablemodes).

## See also

[DXVA_Frequency](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_frequency)

[DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat)