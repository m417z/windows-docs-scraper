# lineSetTollListA function

## Description

The
**lineSetTollList** function manipulates the toll list.

## Parameters

### `hLineApp`

Application handle returned by
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa). If an application has not yet called the
**lineInitializeEx** function, it can set the *hLineApp* parameter to zero.

### `dwDeviceID`

Device identifier for the line device upon which the call is intended to be dialed, so that variations in dialing procedures on different lines can be applied to the translation process.

### `lpszAddressIn`

TBD

### `dwTollListOption`

Toll list operation to be performed. This parameter uses one and only one of the
[LINETOLLLISTOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetolllistoption--constants).

#### - lpszAddressInW

Pointer to a **null**-terminated string containing the address from which the prefix information is to be extracted for processing. This parameter must not be **NULL**, and it must be in the canonical address format.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NODRIVER, LINEERR_INVALAPPHANDLE, LINEERR_NOMEM, LINEERR_INVALADDRESS, LINEERR_OPERATIONFAILED, LINEERR_INVALPARAM, LINEERR_RESOURCEUNAVAIL, LINEERR_INIFILECORRUPT, LINEERR_UNINITIALIZED, LINEERR_INVALLOCATION.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

## Remarks

> [!NOTE]
> The tapi.h header defines lineSetTollList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).