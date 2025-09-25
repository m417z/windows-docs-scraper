# phoneGetButtonInfoW function

## Description

The
**phoneGetButtonInfo** function returns information about the specified button.

## Parameters

### `hPhone`

Handle to the open phone device.

### `dwButtonLampID`

Button on the phone device.

### `lpButtonInfo`

Pointer to a variably sized structure of type
[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo). This data structure describes the mode and the function, and provides additional descriptive text corresponding to the button.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALBUTTONLAMPID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_STRUCTURETOOSMALL, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED.

## See also

[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

## Remarks

> [!NOTE]
> The tapi.h header defines phoneGetButtonInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).