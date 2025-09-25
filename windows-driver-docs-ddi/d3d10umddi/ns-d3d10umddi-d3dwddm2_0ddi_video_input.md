## Description

**D3DWDDM2_0DDI_VIDEO_INPUT** contains input information used by the [**PFND3D10DDI_RETRIEVESUBOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_retrievesubobject) DDI when querying the driver's WDDM 2.0 video functions.

## Members

### `Relocate`

Boolean value that indicates whether the functions can be relocated.

### `pWDDM2_0VideoDeviceFuncs`

A pointer to a [**D3DWDDM2_0DDI_VIDEODEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddi_videodevicefuncs) structure that contains pointers to the video functions being queried.