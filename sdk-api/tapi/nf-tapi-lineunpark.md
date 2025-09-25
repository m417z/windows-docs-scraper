# lineUnpark function

## Description

The
**lineUnpark** function retrieves the call parked at the specified address and returns a call handle for it.

## Parameters

### `hLine`

Handle to the open line device on which a call is to be unparked.

### `dwAddressID`

Address on *hLine* at which the unpark is to be originated. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lphCall`

Pointer to the location of type HCALL where the handle to the unparked call is returned. This handle is unrelated to any other handle that might have been previously associated with the retrieved call, such as the handle that might have been associated with the call when it was originally parked. The application is the initial sole owner of this call.

### `lpszDestAddress`

Pointer to a null-terminated character buffer that contains the address where the call is parked. The address is in standard dialable address format.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESS, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)