# TSPI_phoneGetData function

## Description

The
**TSPI_phoneGetData** function uploads the information from the specified location in the open phone device to the specified buffer.

## Parameters

### `hdPhone`

The handle to the phone to be queried.

### `dwDataID`

Specifies where in the phone device the buffer is to be uploaded from.

### `lpData`

A pointer to the memory buffer where the data is to be uploaded to.

### `dwSize`

The size of the data buffer in bytes. If the *lpData* parameter is a pointer to a string, the size must include the **null** terminator.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INVALDATAID, PHONEERR_RESOURCEUNAVAIL.

## Remarks

The
**TSPI_phoneGetData** function uploads a maximum of *dwSize* bytes from the phone device into *lpData*. If *dwSize* is zero, nothing is copied. The size of each data area is listed in the phone's
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneSetData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetdata)