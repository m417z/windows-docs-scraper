# lineCompleteTransfer function

## Description

The
**lineCompleteTransfer** function completes the transfer of the specified call to the party connected in the consultation call.

## Parameters

### `hCall`

Handle to the call to be transferred. The application must be an owner of this call. The call state of *hCall* must be *onHold* or *onHoldPendingTransfer*.

### `hConsultCall`

Handle to the call that represents a connection with the destination of the transfer. The application must be an owner of this call. The call state of *hConsultCall* must be *connected*, *ringback*, *busy*, or *proceeding*.

### `lphConfCall`

Pointer to a memory location where an *hCall* handle can be returned. If *dwTransferMode* is LINETRANSFERMODE_CONFERENCE, the newly created conference call is returned in *lphConfCall* and the application becomes the sole owner of the conference call. Otherwise, this parameter is ignored by TAPI.

### `dwTransferMode`

How the initiated transfer request is to be resolved. This parameter uses one of the
[LINETRANSFERMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetransfermode--constants).

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_NOTOWNER, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCONSULTCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALTRANSFERMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

The LINE_REPLY message sent in response to a call to the
**lineCompleteTransfer** function is based on the status of the call specified by the *hCall* parameter.

This operation completes the transfer of the original call, *hCall*, to the party currently connected by *hConsultCall*. The consultation call is typically dialed on the consultation call allocated as part of
[lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetuptransfer), but it can be any call to which the switch is capable of transferring *hCall*.

The transfer request can be resolved either as a transfer or as a three-way conference call. When resolved as a transfer, the parties connected by *hCall* and *hConsultCall* are connected to each other, and both *hCall* and *hConsultCall* are typically cleared from the application's line and transition to the *idle* state. The application's call handle remains valid after the transfer has completed. The application must deallocate its handle with
[lineDeallocateCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedeallocatecall) when it is no longer interested in the transferred call.

When resolved as a conference, all three parties enter into a conference call. Both existing call handles remain valid but transition to the *conferenced* state. A conference call handle is created and returned, and it transitions to the *connected* state.

If
[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls) is called immediately after
**lineCompleteTransfer** with the result that the calls are conferenced,
**lineGetConfRelatedCalls** may not return a complete list of related calls. This is because TAPI waits to receive a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message indicating that the call has entered LINECALLSTATE_CONFERENCED before it considers the call to actually be part of the conference. That is, it waits for the service provider to confirm the conferenced state. After the application has received the LINE_CALLSTATE message,
**lineGetConfRelatedCalls** returns complete information.

It can also be possible to perform a blind transfer of a call using
[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer).

## See also

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[Transfer overview](https://learn.microsoft.com/windows/desktop/Tapi/transfer-ovr)

[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer)

[lineDeallocateCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedeallocatecall)

[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls)

[lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetuptransfer)