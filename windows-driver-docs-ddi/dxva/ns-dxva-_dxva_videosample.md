# _DXVA_VideoSample structure

## Description

The DXVA_VideoSample structure is sent by the renderer to the driver to specify the format of a video sample.

## Members

### `rtStart`

Specifies the start time of the sample.

### `rtEnd`

Specifies the end time of the sample.

### `SampleFormat`

Specifies the format of the sample as defined by a [DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat) structure.

### `lpDDSSrcSurface`

Pointer to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure.

## See also

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local)

[DXVA_DeinterlaceBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlaceblt)

[DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat)