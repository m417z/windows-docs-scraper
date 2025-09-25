# phoneSetLamp function

## Description

The
**phoneSetLamp** function causes the specified lamp to be lit on the specified open phone device in the specified lamp mode.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone.

### `dwButtonLampID`

Button whose lamp is to be lit.

### `dwLampMode`

How the lamp is to be lit. This parameter uses one and only one of the
[PHONELAMPMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants).

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding [PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOTOWNER, PHONEERR_NOMEM, PHONEERR_INVALBUTTONLAMPID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALLAMPMODE, PHONEERR_UNINITIALIZED.

## See also

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)