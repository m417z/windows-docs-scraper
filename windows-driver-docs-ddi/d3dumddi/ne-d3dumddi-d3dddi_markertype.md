# D3DDDI_MARKERTYPE enumeration

## Description

Indicates the type of Event Tracing for Windows (ETW) marker event that the user-mode display driver supports.

## Constants

### `D3DDDIMT_NONE`

No marker type is supported. This type is set on creation of the display device.

### `D3DDDIMT_PROFILE`

Profile mode, where the driver estimates the length of time the GPU takes to execute certain operations. The context submits GPU work for single-threaded user-mode DDIs. In this case, each time stamp denotes the end of GPU work.

See Remarks of the [pfnSetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarkermode) function for more info.

## See also

[pfnSetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarkermode)