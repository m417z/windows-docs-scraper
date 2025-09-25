# DXVA2_VideoSample structure

## Description

Specifies an input sample for the [IDirectXVideoProcessor::VideoProcessBlt](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-videoprocessblt) method.

## Members

### `Start`

Start time of the sample, in 100-nanosecond units. For video substream samples, the value is zero.

### `End`

End time of the sample, in 100-nanosecond units. For video substream samples, the value is zero.

### `SampleFormat`

[DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure that describes the interlacing and extended color information for the sample.

### `SrcSurface`

Pointer to the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface of the Direct3D surface that contains the sample.

### `SrcRect`

Source rectangle. The source rectangle defines which portion of the input sample is copied to the destination surface. The source rectangle is specified using pixel coordinates on the input surface.

### `DstRect`

Destination rectangle. The destination rectangle defines the portion of the destination surface where the source rectangle is copied. The destination rectangle is specified using pixel coordinates on the destination surface.

### `Pal`

If the input sample is for a substream and uses a palettized YUV color format, this member contains an array of [DXVA2_AYUVSample8](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_ayuvsample8) structures that define the palette entries. For non-palettized pixel formats, the array elements should all be zero.

### `PlanarAlpha`

Alpha value that will be applied to this input sample when it is composited.

### `SampleData`

Contains additional flags. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **DXVA2_SampleData_RFF** | Repeat first field (RFF) bit. |
| **DXVA2_SampleData_TFF** | Top field first (TFF) bit. |
| **DXVA2_SampleData_RFF_TFF_Present** | If set, the RFF and TFF flags are used. |

These flags provide a hint to the deinterlacer when it performs inverse telecine.

## See also

[DXVA2_AYUVSample8](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_ayuvsample8)

[IDirectXVideoProcessor::VideoProcessBlt](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-videoprocessblt)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)