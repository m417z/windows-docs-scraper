# TSPI_phoneSetData function

## Description

The
**TSPI_phoneSetData** function downloads the information in the specified buffer to the opened phone device at the selected data identifier.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone into which data is to be downloaded.

### `dwDataID`

Specifies where in the phone device the buffer is to be downloaded.

### `lpData`

A pointer to the memory location where the data is to be downloaded from.

### `dwSize`

The size of the buffer in bytes. If the *lpData* parameter is a pointer to a string, the size must include the **null** terminator.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALDATAID, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

The function downloads a maximum of *dwSize* bytes from *lpData* to the phone device. The format of the data, its meaning to the phone device, and the meaning of the data identifier are service-provider specific. The data in the buffer or the selection of a data identifier can act as commands to the phone device.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdata)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)