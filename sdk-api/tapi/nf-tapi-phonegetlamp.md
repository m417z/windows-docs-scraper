# phoneGetLamp function

## Description

The
**phoneGetLamp** function returns the current lamp mode of the specified lamp.

## Parameters

### `hPhone`

Handle to the open phone device.

### `dwButtonLampID`

Identifier of the lamp to be queried.

### `lpdwLampMode`

Pointer to a memory location that holds the lamp mode status of the given lamp. This parameter uses one and only one of the
[PHONELAMPMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALBUTTONLAMPID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## Remarks

Phone sets that have multiple lamps per button should be modeled using multiple button/lamp pairs. Each extra button/lamp pair should use a DUMMY button.

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)