# TSPI_lineSetLineDevStatus function

## Description

The
**TSPI_lineSetLineDevStatus** service provider sets the device status as indicated, sending appropriate
[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85)) messages to indicate the new status.

## Parameters

### `dwRequestID`

Identifier for reporting asynchronous function results.

### `hdLine`

The service provider's handle to the line device.

### `dwStatusToChange`

One or more of the
[LINEDEVSTATUSFLAGS_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstatusflags--constants).

### `fStatus`

**TRUE** to turn on the indicated status bit(s), **FALSE** to turn off.

## Return value

Returns **dwRequestID** if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALLINESTATE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_RESOURCEUNAVAIL.

## See also

[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85))