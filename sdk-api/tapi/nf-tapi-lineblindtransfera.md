# lineBlindTransferA function

## Description

The
**lineBlindTransfer** function performs a blind or single-step transfer of the specified call to the specified destination address.

## Parameters

### `hCall`

Handle to the call to be transferred. The application must be an owner of this call. The call state of *hCall* must be *connected*.

### `lpszDestAddress`

TBD

### `dwCountryCode`

Country or region code of the destination. This is used by the implementation to select the call progress protocols for the destination address. If a value of 0 is specified, a default call-progress protocol defined by the service provider is used.

#### - lpszDestAddressW

Pointer to a null-terminated string identifying where the call is to be transferred to. The destination address uses the standard dialable number format.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_INVALCOUNTRYCODE, LINEERR_INVALCALLSTATE, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONUNAVAIL, LINEERR_NOTOWNER, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALADDRESS, LINEERR_UNINITIALIZED, LINEERR_ADDRESSBLOCKED, LINEERR_OPERATIONFAILED.

## Remarks

If LINEERR_INVALADDRESS is returned, no dialing occurs.

Blind transfer differs from a consultation transfer in that no consultation call is made visible to the application. After the blind transfer successfully completes, the specified call is typically cleared from the application's line, and it transitions to the *idle* state.

The application's call handle remains valid after the transfer has completed. The application must deallocate its handle using
[lineDeallocateCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedeallocatecall) when it is no longer interested in the transferred call.

> [!NOTE]
> The tapi.h header defines lineBlindTransfer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[Transfer overview](https://learn.microsoft.com/windows/desktop/Tapi/transfer-ovr)

[lineDeallocateCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedeallocatecall)