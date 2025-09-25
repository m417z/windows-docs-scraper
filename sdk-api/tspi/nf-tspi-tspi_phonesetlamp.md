# TSPI_phoneSetLamp function

## Description

The
**TSPI_phoneSetLamp** function causes the specified lamp to be set on the specified open phone device in the specified lamp mode.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone whose lamp is to be set.

### `dwButtonLampID`

The button whose lamp is to be set.

### `dwLampMode`

Specifies how the lamp is to be lit. The *dwLampMode* parameter can only have one of the
[PHONELAMPMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants).

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALBUTTONLAMPID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALLAMPMODE, PHONEERR_OPERATIONUNAVAIL.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONELAMPMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonelampmode--constants)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneGetLamp](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetlamp)