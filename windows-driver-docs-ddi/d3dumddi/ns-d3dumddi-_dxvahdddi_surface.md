# _DXVAHDDDI_SURFACE structure

## Description

The DXVAHDDDI_SURFACE structure describes a surface.

## Members

### `hResource` [in]

A handle to the resource that contains the surface.

### `SubResourceIndex` [in]

The zero-based index into the resource, which the handle in the **hResource** member specifies. The **SubResourceIndex** index indicates the surface.

## Remarks

DXVAHDDDI_SURFACE structures are used to describe surfaces in members of the [DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data) and [D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_videoprocessblthd) structures in a call to the driver's [VideoProcessBltHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_videoprocessblthd) function.

## See also

[D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_videoprocessblthd)

[DXVAHDDDI_STREAM_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_data)

[VideoProcessBltHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_videoprocessblthd)