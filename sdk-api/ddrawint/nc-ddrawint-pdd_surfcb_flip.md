## Description

The **DdFlip** callback function causes the surface memory associated with the target surface to become the primary surface, and the current surface to become the nonprimary surface.

## Parameters

### `unnamedParam1`

Points to a [DD_FLIPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_flipdata) structure that contains the information required to perform the flip.

## Return value

**DdFlip** returns one of the following callback codes:

## Remarks

**DdFlip** allows a display driver to perform multibuffering. DirectDraw drivers must implement this function.

The driver should update its surface pointers so that the next frame will be written to the surface to which the **lpSurfTarg** member of the DD_FLIPDATA structure at **lpFlip** points. If a previous flip request is still pending, the driver should fail the call by setting the **ddRVal** member of DD_FLIPDATA to DDERR_WASSTILLDRAWING and returning DDHAL_DRIVER_HANDLED. The driver should ensure that the scan line is not in the vertical blank before performing the flip. **DdFlip** does not affect the actual display of the video data.

If the driver's hardware supports overlays or textures, **DdFlip** should make any necessary checks based on the surface type before performing the flip.

## See also

[DD_FLIPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_flipdata)