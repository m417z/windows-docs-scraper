## Description

The **DdUpdateOverlay** callback function repositions or modifies the visual attributes of an overlay surface.

## Parameters

### `unnamedParam1`

Points to a [DD_UPDATEOVERLAYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_updateoverlaydata) structure that contains the information required to update the overlay.

## Return value

**DdUpdateOverlay** returns one of the following callback codes:

## Remarks

**DdUpdateOverlay** shows, hides, or repositions an overlay surface on the screen. It also sets attributes of the overlay surface, such as the stretch factor or type of color key to be used.

The driver should determine whether it has the bandwidth to support the overlay update request. The driver should use the **dwFlags** member of the DD_UPDATEOVERLAYDATA structure at **lpUpdateOverlay** to determine the type of request and how to process it.

The driver/hardware must stretch or shrink the overlay accordingly when the rectangles specified by the **rDest** and **rSrc** members of DD_UPDATEOVERLAYDATA are different sizes.

Note that [DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip) is used for flipping between overlay surfaces, so performance for **DdUpdateOverlay** is not critical.

## See also

[DD_UPDATEOVERLAYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_updateoverlaydata)

[DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip)

[DdSetColorKey](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setcolorkey)

[DdSetOverlayPosition](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setoverlayposition)