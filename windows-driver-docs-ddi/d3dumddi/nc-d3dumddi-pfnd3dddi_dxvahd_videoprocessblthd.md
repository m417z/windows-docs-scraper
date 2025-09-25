# PFND3DDDI_DXVAHD_VIDEOPROCESSBLTHD callback function

## Description

The *VideoProcessBltHD* function processes video input streams and composes to an output surface.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

*hDevice* [in]

A handle to the display device (graphics context).

*pData* [in]

A pointer to a [D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_videoprocessblthd) structure that describes the DirectX VA video processing operation to perform.

## Return value

*VideoProcessBltHD* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The DirectX VA video processing operation is successfully performed.|
|E_OUTOFMEMORY|VideoProcessBltHD could not allocate memory that was required for it to complete.|

## See also

[D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_videoprocessblthd)