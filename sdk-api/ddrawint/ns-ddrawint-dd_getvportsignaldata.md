# DD_GETVPORTSIGNALDATA structure

## Description

The DD_GETVPORTSIGNALDATA structure contains the signal status of the hardware video port.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `dwStatus`

Specifies the location in which the driver should write the status of the signal at the hardware video port. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPSQ_NOSIGNAL | No video signal is present at the hardware video port. |
| DDVPSQ_SIGNALOK | A valid video signal is present at the hardware video port. |

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetSignalStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getsignalstatus) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoSignalStatus`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortGetSignalStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getsignalstatus)