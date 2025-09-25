# PFND3DDDI_SETVIDEOPROCESSRENDERTARGET callback function

## Description

The *SetVideoProcessRenderTarget* function sets the render target surface that is used for video processing.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETVIDEOPROCESSRENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setvideoprocessrendertarget) structure that describes the render target surface that is used for video processing.

## Return value

*SetVideoProcessRenderTarget* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The render target surface is successfully set.|
|E_OUTOFMEMORY|SetVideoProcessRenderTarget could not allocate the required memory for it to complete.|

## Remarks

*SetVideoProcessRenderTarget* can be called only outside of a [VideoProcessBeginFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessbeginframe)/[VideoProcessEndFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_videoprocessendframe) block.

All video processing render targets are created by setting the [D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags).**VideoProcessRenderTarget** bit-field flag in the **Flags** member of the [D3DDDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddiarg_createresource) structure in a call to the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function.

## See also

[D3DDDIARG_SETVIDEOPROCESSRENDERTARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setvideoprocessrendertarget)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[D3DDDI_RESOURCEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_resourceflags)