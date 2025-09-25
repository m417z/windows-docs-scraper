# PFND3DWDDM1_3DDI_SETMARKERMODE callback function

## Description

Notifies the user-mode display driver that it should support a type of Event Tracing for Windows (ETW) marker event. Must be implemented by Windows Display Driver Model (WDDM) 1.3 and later drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `Type`

A value from the [**D3DWDDM1_3DDI_MARKER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_marker_type) enumeration that indicates the type of marker event that the driver should support.

### `Flags`

A UINT value that indicates whether the driver should provide custom info in command buffers. If set to **D3DWDDM1_3DDI_SETMARKERMODE_CUSTOMDRIVEREVENTS**, the driver should annotate and instrument command buffers with custom event info. Otherwise, the driver should not annotate command buffers.

The annotation can be in the form of a text string in the English-US locale, or in the form of an index value to a location in a string table. For the latter option, the driver must also implement a function that describes the strings that the index values indicate.

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

Follow these guidelines when you set up profile-type marker events in your user-mode driver, indicated by the **D3DWDDM1_3DDI_MARKER_TYPE_PROFILE** type:

* Use lightweight instrumentation that doesn't produce a strong correlation with graphics command boundaries.
* The driver must be able to sample the GPU time stamp at the end of the graphics pipeline.
* Don't use sampling commands that place a high performance burden on the graphics pipeline, such as wait-for-idle commands. To be able to instrument profile-type marker events, your driver shouldn't have to flush the pipeline or caches.

## See also

[**D3DWDDM1_3DDI_MARKER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm1_3ddi_marker_type)