# TSPI_providerCreateLineDevice function

## Description

The
**TSPI_providerCreateLineDevice** function is called by TAPI in response to receipt of a
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) message from the service provider, which allows the dynamic creation of a new line device.

## Parameters

### `dwTempID`

The temporary device identifier that the service provider passed to TAPI in the
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) message.

### `dwDeviceID`

The device identifier that TAPI assigns to this device if this function succeeds.

## Return value

Returns zero if the request succeeds or an error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## Remarks

When TAPI receives a
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) message from a service provider, it calls this function (it never calls this function spontaneously). TAPI adds 1 to the number of devices of that type, and passes the resulting new, unused device identifier as the *dwDeviceID* parameter to this function. It also passes in the function the *dwParam2* parameter from the LINE_CREATE message as *dwTempID*.

**Note** Adding the new device to the end of the device list is likely to produce noncontiguous device identifiers for the service provider; service providers that support dynamic device creation must also support noncontiguous device identifiers.

If the service provider recognizes the *dwTempID* and succeeds in setting up the structures and such that it needs to support the new device, it saves off the *dwDeviceID*, and returns SUCCESS. If this function is unsuccessful, TAPI doesn't add the device, and there are no negative effects (the
[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85)) message is ignored). If this function completes successfully, TAPI then informs applications of the availability of the new device using LINE_CREATE or
[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85)) (LINEDEVSTATE_REINIT) messages.

Older service providers that do not export this function, however, also should not send LINE_CREATE messages, which means TAPI would not try to call this function.

## See also

[LINE_CREATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725223(v=vs.85))

[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85))