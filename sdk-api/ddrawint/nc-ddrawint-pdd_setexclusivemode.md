## Description

The *DdSetExclusiveMode* callback function notifies the driver when a DirectDraw application is switching to or from exclusive mode.

## Parameters

### `unnamedParam1`

Points to a [DD_SETEXCLUSIVEMODEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setexclusivemodedata) structure that contains the notification information.

## Return value

*DdSetExclusiveMode* returns one of the following callback codes:

## Remarks

*DdSetExclusiveMode* can be optionally implemented in display drivers. Drivers for hardware that needs to be partially enabled and/or disabled to support exclusive mode should implement this function.

DirectDraw applications can go full screen and take total control of the primary surface. Specifically, the application is responsible for operations such as DirectDraw mode changes and primary surface flipping when in exclusive mode.

## See also

[DD_SETEXCLUSIVEMODEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setexclusivemodedata)