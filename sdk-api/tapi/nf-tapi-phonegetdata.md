# phoneGetData function

## Description

The
**phoneGetData** function uploads the information from the specified location in the open phone device to the specified buffer.

## Parameters

### `hPhone`

Handle to the open phone device.

### `dwDataID`

Where in the phone device the buffer is to be uploaded from.

### `lpData`

Pointer to the memory buffer where the data is to be uploaded.

### `dwSize`

Size of the data buffer, in bytes.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALDATAID, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The function uploads a maximum of *dwSize* bytes from the phone device into the memory area pointed to by *lpData*. If *dwSize* is zero, nothing is copied. The size of each data area is listed in the phone's device capabilities.

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)