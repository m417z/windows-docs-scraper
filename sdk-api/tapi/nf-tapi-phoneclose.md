# phoneClose function

## Description

The
**phoneClose** function closes the specified open phone device.

## Parameters

### `hPhone`

Handle to the open phone device to be closed. If the function succeeds, the handle is no longer valid.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_OPERATIONFAILED, PHONEERR_RESOURCEUNAVAIL, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED.

## Remarks

After the open phone device has been successfully closed, the implementation sends a
[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close) message to the application. These messages can also be sent unsolicited as a result of the phone device being reclaimed somehow. An application should therefore be prepared to handle these unsolicited close messages. At the time the phone device is closed, any outstanding asynchronous replies are suppressed.

## See also

[PHONE_CLOSE](https://learn.microsoft.com/windows/desktop/Tapi/phone-close)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)