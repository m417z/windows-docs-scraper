# DD_VPORTCOLORDATA structure

## Description

The DD_VPORTCOLORDATA structure contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object color control information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this VPE object.

### `dwFlags`

Specifies the color control operation to be performed by the driver. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDRAWI_VPORTGETCOLOR | The driver should write the current VPE object color controls into the DDCOLORCONTROL structure to which **lpColorData** points. |
| DDRAWI_VPORTSETCOLOR | The driver should set new values for the VPE object color controls based on the contents of the DDCOLORCONTROL structure to which **lpColorData** points. |

### `lpColorData`

Points to a [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure that defines the color control associated with the VPE object to which **lpVideoPort** points. The value of **dwFlags** determines whether the driver reads from or writes to this structure.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortColorControl](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_colorcontrol) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `ColorControl`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85))

[DdVideoPortColorControl](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_colorcontrol)