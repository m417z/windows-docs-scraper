# PFND3D11_1DDI_VIDEOPROCESSORINPUTVIEWREADAFTERWRITEHAZARD callback function

## Description

Notifies the display miniport driver that the [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt) function is about to be called to read from a specified input view resource for a video processor. This resource had previously been written to by either the [VideoDecoderSubmitBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecodersubmitbuffers) or the [DecryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_decryptionblt) functions.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hView* [in]

A handle to the driver's private data for the video processor input view that was created through a call to the [CreateVideoProcessorInputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview) function.

### `unnamedParam3`

*hResource* [in]

A handle to the driver's private data for an input view resource object. This handle is created though a call to the [CreateVideoProcessorInputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview) function.

## See also

[CreateVideoProcessorInputView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview)

[DecryptionBlt(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_decryptionblt)