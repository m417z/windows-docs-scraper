# lineSetLineDevStatus function

## Description

The
**lineSetLineDevStatus** function sets the line device status. Except for basic parameter validation, it is a straight pass-through to the service provider. The service provider sends a
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) message to inform applications of the new state, when set; TAPI does not synthesize these messages.

## Parameters

### `hLine`

Handle to the line device.

### `dwStatusToChange`

One or more of the
[LINEDEVSTATUSFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstatusflags--constants).

### `fStatus`

**TRUE** (–1) to turn on the indicated status bit(s), **FALSE** (0) to turn off.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALLINESTATE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONUNAVAIL, LINEERR_OPERATIONFAILED, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.