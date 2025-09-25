# PFND3DWDDM2_0DDI_VIDEOPROCESSORGETBEHAVIORHINTS callback function

## Description

Returns driver hints as to which video processor operations are best performed using multi-plane overlay hardware rather than [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt). Optional for Windows Display Driver Model (WDDM) 2.0, or later, drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hVideoProcessor`

Handle to the video processor object.

### `OutputWidth`

Indicates the width of the output surface.

### `OutputHeight`

Indicates the height of the output surface.

### `OutputFormat`

Indicates the output format of the video processor.

### `StreamCount`

The number of input streams to process.

### `pStreams`

An array of structures indicating the format and status of each stream.

### `pBehaviorHints`

Receives a combination of **D3DWDDM2_0DDI_VIDEO_PROCESSOR_MULTIPLANE_BEHAVIOR_HINTS** values indicting which of the operations would best be performed using multi-plane overlay hardware rather than with [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt).

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function uses the current state, set via the **VideoProcessorSetOutput** and **VideoProcessorSetStream** set of device driver interfaces (DDIs), and returns which operations could be performed more efficiently using multiple overlay hardware.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt)