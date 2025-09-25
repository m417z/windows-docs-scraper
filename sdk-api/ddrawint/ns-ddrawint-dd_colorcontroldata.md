# DD_COLORCONTROLDATA structure

## Description

The DD_COLORCONTROLDATA structure contains the color control information for the specified overlay.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the overlay surface.

### `lpColorData`

Points to a [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure. See the **dwFlags** member to determine how to use this member.

### `dwFlags`

Indicates a set of flags that specify the color control flags. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDRAWI_GETCOLOR | The driver should return the color controls it supports for the specified overlay in the **lpColorData** member. The driver should set the appropriate flags in the **dwFlags** member of the [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure to indicate in which other members the driver has returned valid data. |
| DDRAWI_SETCOLOR | The driver should set the current color controls for the specified overlay using the values specified in the **lpColorData** member. |

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdControlColor](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_colorcb_colorcontrol) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `ColorControl`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdControlColor](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_colorcb_colorcontrol)