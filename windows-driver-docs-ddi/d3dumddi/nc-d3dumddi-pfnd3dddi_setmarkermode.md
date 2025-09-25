# PFND3DDDI_SETMARKERMODE callback function

## Description

Notifies the user-mode display driver that it should support a type of Event Tracing for Windows (ETW) marker event. Optionally implemented by Windows Display Driver Model (WDDM) 1.3 and later drivers running on Microsoft Direct3D Level 9 hardware. (See requirements in [Direct3D rendering performance improvements](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-rendering-performance-improvements).) For more advanced hardware, drivers should implement the [SetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarkermode) function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `Type`

A value from the [D3DDDI_MARKERTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markertype) enumeration that indicates the type of marker event that the driver should support.

### `Flags`

A **UINT** value that indicates whether the driver should provide custom info in command buffers. If set to **D3DDDI_SETMARKERMODE_CUSTOMDRIVEREVENTS**, the driver should annotate and instrument command buffers with custom event info. Otherwise, the driver should not annotate command buffers.

The annotation can be in the form of a text string in the English-US locale, or in the form of an index value to a location in a string table. For the latter option, the driver must also implement a function that describes the strings that the index values indicate.

## Return value

 Returns **S_OK** or an appropriate error result if the function does not complete successfully.

## Remarks

Follow these guidelines when you set up profile-type marker events in your user-mode driver, indicated by the **D3DDDIMT_PROFILE** type:

1. Use lightweight instrumentation that doesn't produce a strong correlation with graphics command boundaries.
2. The driver must be able to sample the GPU time stamp at the end of the graphics pipeline.
3. Don't use sampling commands that place a high performance burden on the graphics pipeline, such as wait-for-idle commands. To be able to instrument profile-type marker events, your driver shouldn't have to flush the pipeline or caches.

## See also

[D3DDDI_MARKERTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markertype)

[SetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarkermode)