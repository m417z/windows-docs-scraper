# lineGetAddressIDA function

## Description

The
**lineGetAddressID** function returns the address identifier associated with an address in a different format on the specified line.

## Parameters

### `hLine`

Handle to the open line device.

### `lpdwAddressID`

Pointer to a **DWORD**-sized memory location where the address identifier is returned. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwAddressMode`

Address mode of the address contained in *lpsAddress*. This parameter uses one and only one of the
[LINEADDRESSMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressmode--constants). You must specify LINEADDRESSMODE_DIALABLEADDR.

### `lpsAddress`

Pointer to a data structure holding the address assigned to the specified line device. The format of the address is determined by *dwAddressMode*. Because the only valid value is LINEADDRESSMODE_DIALABLEADDR, *lpsAddress* uses the common dialable number format and is null-terminated.

### `dwSize`

Size, in bytes, of the address contained in *lpsAddress*. The size of the string must include the null terminator.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALADDRESS, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

The
**lineGetAddressID** function is used to map a phone number (address) assigned to a line device back to its *dwAddressID* in the range zero to the number of addresses minus one returned in the line's device capabilities. The
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) function allows the application to make a call by specifying a line handle and an address on the line. The address can be specified as a *dwAddressID*, as a phone number, or as a device-specific name or identifier. Using a phone number can be practical in environments where a single line is assigned multiple addresses.

**Note** LINEADDRESSMODE_ADDRESSID may not be used with
**lineGetAddressID**.

> [!NOTE]
> The tapi.h header defines lineGetAddressID as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)