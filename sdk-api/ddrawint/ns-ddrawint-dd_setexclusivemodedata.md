# DD_SETEXCLUSIVEMODEDATA structure

## Description

The DD_SETEXCLUSIVEMODEDATA structure contains the exclusive mode notification information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `dwEnterExcl`

Indicates that a Microsoft DirectDraw application is switching into exclusive mode when **TRUE**; indicates that a DirectDraw application is leaving exclusive mode when **FALSE**.

### `dwReserved`

This is reserved for system use and should be ignored by the driver.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSetExclusiveMode](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_setexclusivemode) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `SetExclusiveMode`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdSetExclusiveMode](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_setexclusivemode)