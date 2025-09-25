# PFND3DDDI_SETMARKER callback function

## Description

Notifies the user-mode display driver that it must generate a new time stamp if any GPU work has completed since the last call to *pfnSetMarker*. Optionally implemented by Windows Display Driver Model (WDDM) 1.3 and later drivers running on Microsoft Direct3D Level 9 hardware. (See requirements in [Direct3D rendering performance improvements](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-rendering-performance-improvements).) For more advanced hardware, drivers should implement the [SetMarker](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarker) function.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

## Return value

 Returns **S_OK** or an appropriate error result if the function does not complete successfully.

## Remarks

If the marker event type from the *Type* parameter of the [pfnSetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarkermode) function is not **D3DDDIMT_NONE**, the user-mode display driver must perform this procedure with each call to *pfnSetMarker*:

1. Increment the value of the **APISequenceNumber** member of the [D3DDDICB_LOGUMDMARKER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_logumdmarker) structure.
2. Determine which contexts associated with single-threaded device driver interface (DDI) render calls submitted work with the last call to *pfnSetMarker*. For each such context:
   1. If the command buffer for the context is empty, do nothing.
   2. Otherwise:
      * Ensure that more memory is available in the context's history buffer. Flush the buffer if necessary.
      * Add another entry to the context's API sequence number buffer that contains the low 32 bits of the current **APISequenceNumber** value.
      * Sample and write out time stamps that are appropriate for the current marker event type.
   3. Update tracking data that will be used the next time that *pfnSetMarker* is called.

## See also

[SetMarker](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarker)

[pfnSetMarkerMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarkermode)