# PFND3D11_1DDI_VIDEODECODERGETHANDLE callback function

## Description

Returns the driver's handle for a video decoder that can be used by the application to configure content protection.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hDecoder* [in]

A handle to the video decoder object that was created through a call to the [CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

### `pContentProtectionHandle`

A pointer to the handle.

## Return value

**VideoDecoderGetHandle** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The handle was returned successfully.|
|D3DDDIERR_DEVICEREMOVED|The graphics adapter was removed.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The **VideoDecoderGetHandle** function returns a driver handle for the video decoder. This handle can be used by the application to associate the decoder with a cryptographic session over the authenticated channel.

This function allows the driver to define its own handle to its state data for the video decoder. This bypasses any handle mapping that may be performed by the Microsoft Direct3D runtime.

**Note** Drivers can return the same handle in the *pHandle* parameter that was passed in the *hDecoder* parameter.

## See also

[CreateVideoDecoder](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder)

[D3D11_1DDIARG_VIDEODECODEREXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_videodecoderextension)