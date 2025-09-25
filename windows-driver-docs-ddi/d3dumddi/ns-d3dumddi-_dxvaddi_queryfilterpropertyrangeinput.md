# _DXVADDI_QUERYFILTERPROPERTYRANGEINPUT structure

## Description

The DXVADDI_QUERYFILTERPROPERTYRANGEINPUT structure describes a filter setting on a video stream that range information is requested for.

## Members

### `pVideoProcGuid` [in]

A pointer to a GUID that represents the video processing device type.

### `VideoDesc` [in]

A [DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc) structure that describes the video stream.

### `RenderTargetFormat` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the render target for the video processing device.

### `FilterSetting` [in]

A filter setting that range information is requested for. This member can be one of the following settings:

* DXVADDI_NOISEFILTER_LUMALEVEL
* DXVADDI_NOISEFILTER_LUMATHREASHOLD
* DXVADDI_NOISEFILTER_LUMARADIUS
* DXVADDI_NOISEFILTER_CHROMALEVEL
* DXVADDI_NOISEFILTER_CHROMATHREASHOLD
* DXVADDI_NOISEFILTER_CHROMARADIUS
* DXVADDI_DETAILFILTER_LUMALEVEL
* DXVADDI_DETAILFILTER_LUMATHREASHOLD
* DXVADDI_DETAILFILTER_LUMARADIUS
* DXVADDI_DETAILFILTER_CHROMALEVEL
* DXVADDI_DETAILFILTER_CHROMATHREASHOLD
* DXVADDI_DETAILFILTER_CHROMARADIUS

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[DXVADDI_VALUERANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_valuerange)

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)