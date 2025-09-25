# lineSetupTransferA function

## Description

The
**lineSetupTransfer** function initiates a transfer of the call specified by the *hCall* parameter. It establishes a consultation call, *lphConsultCall*, on which the party can be dialed that can become the destination of the transfer. The application acquires owner privilege to the *lphConsultCall* parameter.

## Parameters

### `hCall`

Handle to the call to be transferred. The application must be an owner of the call. The call state of *hCall* must be *connected*.

### `lphConsultCall`

Pointer to an *hCall* handle. This location is then loaded with a handle identifying the temporary consultation call. When setting up a call for transfer, a consultation call is automatically allocated that enables
[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial) to dial the address associated with the new transfer destination of the call. The originating party can carry on a conversation over this consultation call prior to completing the transfer. The call state of *hConsultCall* is not applicable.

This transfer procedure may not be valid for some line devices. The application may need to ignore the new consultation call and unhold an existing held call (using
[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold)) to identify the destination of the transfer. On switches that support cross-address call transfer, the consultation call can exist on a different address than the call to be transferred. It may also be necessary that the consultation call be set up as an entirely new call, by
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall), to the destination of the transfer. Which forms of transfer are available are specified in the call's address capabilities.

### `lpCallParams`

Pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure containing the call parameters to use when establishing the consultation call. This parameter can be set to **NULL** if no special call setup parameters are desired.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_BEARERMODEUNAVAIL, LINEERR_INVALRATE, LINEERR_CALLUNAVAIL, LINEERR_NOMEM, LINEERR_INUSE, LINEERR_NOTOWNER, LINEERR_INVALADDRESSMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALBEARERMODE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_RATEUNAVAIL, LINEERR_INVALCALLPARAMS, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALLINESTATE, LINEERR_UNINITIALIZED, LINEERR_INVALMEDIAMODE, LINEERR_USERUSERINFOTOOBIG, LINEERR_INVALPOINTER.

## Remarks

The
**lineSetupTransfer** function sets up the transfer of the call specified by *hCall*. The setup phase of a transfer establishes a consultation call that enables the application to send the address of the destination (the party to be transferred to) to the switch, while the call to be transferred is kept on hold. This new call is referred to as a consultation call (*hConsultCall*) and can be dropped or otherwise manipulated independently of the original call.

When the consultation call has reached the *dialtone* call state, the application can proceed transferring the call either by dialing the destination address and tracking its progress, or by unholding an existing call. The transfer of the original call to the selected destination is completed using
[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer).

While the consultation call exists, the original call typically transitions to the *onholdPendingTransfer* state. The application may be able to toggle between the consultation call and the original call by using
[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold). A consultation call can be canceled by invoking
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop) on it. After dropping a consultation call, the original call typically transitions back to the *connected* state. If the call state of the original call is *onholdPendingTransfer*, the
[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold) function can be used to recover the call. In this case, the call state of the consultation call is set to *idle*.

The application can also transfer calls in a single step, without having to deal with the intervening consultation call, by using
[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer).

> [!NOTE]
> The tapi.h header defines lineSetupTransfer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[Transfer Overview](https://learn.microsoft.com/windows/desktop/Tapi/transfer-ovr)

[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer)

[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer)

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold)

[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold)