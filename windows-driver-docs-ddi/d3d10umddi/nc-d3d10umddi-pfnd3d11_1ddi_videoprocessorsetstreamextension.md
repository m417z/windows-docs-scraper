# PFND3D11_1DDI_VIDEOPROCESSORSETSTREAMEXTENSION callback function

## Description

Sets the private state data for a video processor stream from an application.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hVideoProcessor* [in]

A handle to the video processor object that was created through a call to the [CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `unnamedParam3`

*StreamIndex* [in]

The zero-based index of the input stream.

### `unnamedParam4`

*pGuid* [in]

A pointer to a GUID that identifies the private state data. The meaning of this GUID is defined by the graphics driver.

### `unnamedParam5`

*DataSize* [in]

The size, in bytes, of the private state data in the buffer referenced by the *pData* parameter.

### `unnamedParam6`

*pData* [in, out]

A pointer to a buffer that contains the private state data.

> [!NOTE]
> The Direct3D runtime does not validate the private state data in the buffer before it calls the **VideoProcessorSetStreamExtension** function

## Return value

**VideoProcessorSetStreamExtension** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The private state data was set successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|E_FAIL|The display miniport driver cannot set the requested private state data for the video processor.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor)