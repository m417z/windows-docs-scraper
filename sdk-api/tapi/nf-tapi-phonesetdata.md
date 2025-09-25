# phoneSetData function

## Description

The
**phoneSetData** function downloads the information in the specified buffer to the opened phone device at the selected data identifier.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone.

### `dwDataID`

Where in the phone device the buffer is to be downloaded.

### `lpData`

Pointer to the memory location where the data is to be downloaded from.

### `dwSize`

Size of the buffer, in bytes.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOTOWNER, PHONEERR_NOMEM, PHONEERR_INVALDATAID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPOINTER, PHONEERR_UNINITIALIZED.

## Remarks

The
**phoneSetData** function downloads a maximum of *dwSize* bytes from *lpData* to the phone device. The format of the data, its meaning to the phone device, and the meaning of the data identifier are service provider-specific. The data in the buffer or the selection of a data identifier may act as commands to the phone device.

## See also

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)