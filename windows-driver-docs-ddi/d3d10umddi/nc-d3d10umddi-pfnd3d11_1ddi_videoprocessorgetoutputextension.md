# PFND3D11_1DDI_VIDEOPROCESSORGETOUTPUTEXTENSION callback function

## Description

Returns private state data from a video processor to an application.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*pGuid* [in]

A pointer to a GUID that identifies the private state data. The meaning of this GUID is defined by the graphics driver.

### `unnamedParam4`

*DataSize* [in]

The size, in bytes, of the private state data in the buffer referenced by the *pData* parameter.

### `unnamedParam5`

*pData* [in, out]

A pointer to a buffer that receives the private state data.

## Return value

**VideoProcessorGetOutputExtension** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The private state data was returned successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|E_FAIL|The display miniport driver cannot return the requested private state data from the video processor.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The Microsoft Direct3D runtime does not validate any parameter data before it calls the [VideoProcessorSetOutputExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputextension) function.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)