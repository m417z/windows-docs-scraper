# DD_WAITFORVPORTSYNCDATA structure

## Description

The DD_WAITFORVPORTSYNCDATA structure contains the information required for the driver to synchronize the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this VPE object.

### `dwFlags`

Indicates the condition for which the driver should wait. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPWAIT_BEGIN | The driver should return at the beginning of the next V-sync. |
| DDVPWAIT_END | The driver should return at the end of the next/current V-sync. |
| DDVPWAIT_LINE | The driver should return at the beginning of the line specified in **dwLine**. |

### `dwLine`

Specifies the line number on which the driver should synchronize when **dwFlags** is DDVPWAIT_LINE. The driver should ignore this member when **dwFlags** is set to DDVPWAIT_BEGIN or DDVPWAIT_END.

### `dwTimeOut`

Specifies the maximum amount of time the driver should wait, in milliseconds, before timing out.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortWaitForSync](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_waitforsync) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `UpdateVideoPort`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortWaitForSync](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_waitforsync)