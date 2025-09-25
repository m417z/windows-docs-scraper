# TSPI_phoneGetLamp function

## Description

The
**TSPI_phoneGetLamp** function returns the current lamp mode of the specified lamp.

## Parameters

### `hdPhone`

The handle to the phone whose lamp mode is to be retrieved.

### `dwButtonLampID`

The identifier of the lamp to be queried.

### `lpdwLampMode`

A pointer to a memory location into which the service provider writes the lamp mode status of the given lamp. This parameter can have at most one of the
[PHONELAMPMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALBUTTONLAMPID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

Phone sets that have multiple lamps per button should be modeled using multiple button/lamps pairs. Each additional button/lamp pair should use a DUMMY button.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[PHONELAMPMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneSetLamp](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetlamp)