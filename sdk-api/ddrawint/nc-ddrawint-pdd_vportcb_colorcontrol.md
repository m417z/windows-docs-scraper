## Description

The **DdVideoPortColorControl** callback function gets or sets the VPE object color controls.

## Parameters

### `unnamedParam1`

Points to a [DD_VPORTCOLORDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_vportcolordata) structure that contains the information required for the driver to get the current VPE object color controls or to set new values.

## Return value

**DdVideoPortColorControl** returns one of the following callback codes:

## Remarks

DirectDraw drivers that set the DDVPCAPS_COLORCONTROL flag in the [DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps) structure must implement **DdVideoPortColorControl**.

Depending on the value of the **dwFlags** member of the DD_VPORTCOLORDATA structure at *lpColorControl*, the driver should do the following:

* When **dwFlags** is DDRAWI_VPORTGETCOLOR, the driver should fill in each member of the [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure that it supports with the VPE object's current color control setting. The driver must set the corresponding bit in the **dwFlags** member of DDCOLORCONTROL for every color control member in which it writes data.

  **DdVideoPortColorControl** can be called to determine the color control capabilities of the VPE object. The driver should therefore fail the call if it does not support a requested color control capability.
* When **dwFlags** is DDRAWI_VPORTSETCOLOR, the driver should set the VPE object's color control settings to the values specified in the DDCOLORCONTROL structure. The driver should check the **dwFlags** member of DDCOLORCONTROL to determine which structure members contain valid data.

## See also

[DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85))

[DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps)

[DD_VPORTCOLORDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_vportcolordata)