# PFND3DWDDM1_3DDI_SETMARKER callback function

## Description

Notifies the user-mode display driver that it must generate a new time stamp if any GPU work has completed since the last call to **SetMarker**.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

If the marker event type from the **Type** parameter of the [**SetMarkerMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarkermode) function is not **D3DWDDM1_3DDI_MARKER_TYPE_NONE**, the user-mode display driver must perform this procedure with each call to **SetMarker**:

1. Increment the value of the **APISequenceNumber** member of the [**D3DDDICB_LOGUMDMARKER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_logumdmarker) structure.
2. Determine which contexts associated with single-threaded device driver interface (DDI) render calls submitted work with the last call to **SetMarker**. For each such context:

   * If the command buffer for the context is empty, do nothing.
   * Otherwise:
     * Ensure that more memory is available in the context's history buffer. Flush the buffer if necessary.
     * Add another entry to the context's API sequence number buffer that contains the low 32 bits of the current **APISequenceNumber** value.
     * Sample and write out time stamps that are appropriate for the current marker event type.

3. Update tracking data that will be used the next time that **SetMarker** is called.

## See also

[**SetMarkerMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm1_3ddi_setmarkermode)