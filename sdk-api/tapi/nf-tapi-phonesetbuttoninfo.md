# phoneSetButtonInfo function

## Description

The
**phoneSetButtonInfo** function sets information about the specified button on the specified phone.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone device.

### `dwButtonLampID`

Button on the phone device.

### `lpButtonInfo`

Pointer to a variably sized structure of type
[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo). This data structure describes the mode, the function, and provides additional descriptive text about the button.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALBUTTONLAMPID, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONEHANDLE, PHONEERR_STRUCTURETOOSMALL, PHONEERR_INVALPOINTER, PHONEERR_UNINITIALIZED, PHONEERR_NOTOWNER, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_RESOURCEUNAVAIL.

## See also

[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo)

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)