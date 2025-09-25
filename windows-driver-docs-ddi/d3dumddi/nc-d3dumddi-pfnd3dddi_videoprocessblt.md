# PFND3DDDI_VIDEOPROCESSBLT callback function

## Description

The *VideoProcessBlt* function processes a video frame by using the specified Microsoft DirectX Video Accelerator (VA) video processing device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_VIDEOPROCESSBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessblt) structure that describes the DirectX VA video processing operation to perform.

## Return value

*VideoProcessBlt* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The DirectX VA video processing operation is successfully performed. |
| **E_OUTOFMEMORY** | VideoProcessBlt could not allocate the required memory for it to complete. |

## See also

[D3DDDIARG_VIDEOPROCESSBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessblt)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)