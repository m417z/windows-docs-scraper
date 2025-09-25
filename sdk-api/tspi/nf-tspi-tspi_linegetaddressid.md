# TSPI_lineGetAddressID function

## Description

The
**TSPI_lineGetAddressID** function returns the address identifier associated with address in a different format on the specified line.

## Parameters

### `hdLine`

The service provider's handle to the line whose address is to be retrieved.

### `lpdwAddressID`

A pointer to a **DWORD**-sized memory location where the address identifier is returned.

### `dwAddressMode`

The address mode of the address contained in *lpsAddress*. The *dwAddressMode* parameter is allowed to have one and only one of the
[LINEADDRESSMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressmode--constants).

### `lpsAddress`

A pointer to a data structure holding the address assigned to the specified line device. The format of the address is determined by the *dwAddressMode* parameter. If it is LINEADDRESSMODE_DIALABLEADDR, the *lpsAddress* parameter uses the common dialable number format and is **NULL** terminated.

### `dwSize`

The size of the address contained in *lpsAddress*. The parameter *dwSize* must be set to the length of the string (plus one for the **NULL**) if LINEADDRESSMODE_DIALABLEADDR is used. If an extended LINEADDRESSMODE is used, the length should match the size of whatever is actually passed in (the DLL checks to be sure it can read the number of bytes specified from the given pointer).

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESS, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

This function is used to map a phone number (address) assigned to a line device back to its *dwAddressID* (in the range from 0 through the number of addresses minus one) that is returned in the line's device capabilities.

## See also

[LINEADDRESSMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressmode--constants)