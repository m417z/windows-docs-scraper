## Description

The **DdSetOverlayPosition** callback function sets the position for an overlay.

## Parameters

### `unnamedParam1`

Points to a [DD_SETOVERLAYPOSITIONDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setoverlaypositiondata) structure that contains the information required to set the overlay position.

## Return value

**DdSetOverlayPosition** returns one of the following callback codes:

## Remarks

When the overlay is visible, the driver should cause the overlay to be displayed on the primary surface. The upper left corner of the overlay should be anchored at the position specified by the **lXPos** and **lYPos** members of the [DD_SETOVERLAYPOSITIONDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setoverlaypositiondata) structure at *lpSetOverlayPosition*. For example, values of (0,0) indicate that the upper left corner of the overlay should appear in the upper left corner of the surface identified by the **lpDDDestSurface** member of DD_SETOVERLAYPOSITIONDATA.

When the overlay is invisible, the driver should set an error code in the **ddRVal** member of DD_SETOVERLAYPOSITIONDATA and return DDHAL_DRIVER_HANDLED.

## See also

[DD_SETOVERLAYPOSITIONDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setoverlaypositiondata)