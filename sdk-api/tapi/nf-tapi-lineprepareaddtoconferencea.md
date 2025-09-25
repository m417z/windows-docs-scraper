# linePrepareAddToConferenceA function

## Description

The
**linePrepareAddToConference** function prepares an existing conference call for the addition of another party.

## Parameters

### `hConfCall`

Handle to a conference call. The application must be an owner of this call. The call state of *hConfCall* must be *connected*.

### `lphConsultCall`

Pointer to an HCALL handle. This location is then loaded with a handle identifying the consultation call to be added. Initially, the application is the sole owner of this call.

### `lpCallParams`

Pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure containing call parameters to use when establishing the consultation call. This parameter can be set to **NULL** if no special call setup parameters are desired.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_BEARERMODEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_CALLUNAVAIL, LINEERR_INVALRATE, LINEERR_CONFERENCEFULL, LINEERR_NOMEM, LINEERR_INUSE, LINEERR_NOTOWNER, LINEERR_INVALADDRESSMODE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALBEARERMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLPARAMS, LINEERR_RATEUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCONFCALLHANDLE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALLINESTATE, LINEERR_USERUSERINFOTOOBIG, LINEERR_INVALMEDIAMODE, LINEERR_UNINITIALIZED.

## Remarks

If LINEERR_INVALLINESTATE is returned, the line is currently not in a state in which this operation can be performed. A list of currently valid operations can be found in the **dwLineFeatures** member (of the type
[LINEFEATURE](https://learn.microsoft.com/windows/desktop/Tapi/linefeature--constants)) in the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure. (Calling
[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus) updates the information in
**LINEDEVSTATUS**.)

A conference call handle can be obtained with
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference) or with
[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer) that is resolved as a three-way conference call. The
**linePrepareAddToConference** function typically places the existing conference call in the *onHoldPendingConference* state and creates a consultation call that can be added later to the existing conference call with
[lineAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineaddtoconference).

The consultation call can be canceled using
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop). It may also be possible for an application to swap between the consultation call and the held conference call with
[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold).

> [!NOTE]
> The tapi.h header defines linePrepareAddToConference as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Conference overview](https://learn.microsoft.com/windows/desktop/Tapi/conference-ovr)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[lineAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineaddtoconference)

[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus)

[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference)

[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold)