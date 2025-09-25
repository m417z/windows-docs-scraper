# TSPI_phoneSetButtonInfo function

## Description

The
**TSPI_phoneSetButtonInfo** function sets information about the specified button on the specified phone.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request. The service provider returns this value if the function completes asynchronously.

### `hdPhone`

The handle to the phone for which button info is to be set.

### `dwButtonLampID`

A button on the phone device.

### `lpButtonInfo`

A pointer to a variably sized structure of type
[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo). This data structure describes the mode and function, and provides additional descriptive text to be set for the button.

## Return value

Returns the (positive) *dwRequestID* value if the function is completed asynchronously, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALBUTTONLAMPID, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

This function sets the meaning and associated descriptive text of a phone's buttons.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONEBUTTONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonebuttoninfo)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetButtonInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetbuttoninfo)