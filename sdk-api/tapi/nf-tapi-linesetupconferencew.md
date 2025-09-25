# lineSetupConferenceW function

## Description

The
**lineSetupConference** function sets up a conference call for the addition of the third party.

## Parameters

### `hCall`

Handle to the Initial call that identifies the first party of a conference call. In some environments (as described in device capabilities), a call must exist to start a conference call, and the application must be an owner of this call. In other telephony environments, no call initially exists, *hCall* must be left **NULL**, and *hLine* must be specified to identify the line on which the conference call is to be initiated. The call state of *hCall* must be *connected*.

### `hLine`

Handle to the line. This handle is used to identify the line device on which to originate the conference call if *hCall* is **NULL**. The *hLine* parameter is ignored if *hCall* is non-**NULL**.

### `lphConfCall`

Pointer to an HCALL handle. This location is then loaded with a handle identifying the newly created conference call. The application is the initial sole owner of this call. The call state of *hConfCall* is not applicable.

### `lphConsultCall`

Pointer to an HCALL handle. When setting up a call for the addition of a new party, a new temporary call (consultation call) is automatically allocated. Initially, the application is the sole owner for this call.

### `dwNumParties`

Expected number of parties in the conference call. This number is passed to the service provider. The service provider is free to do as it pleases with this number: ignore it, use it as a hint to allocate the right size conference bridge inside the switch, and so on.

### `lpCallParams`

Pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure containing call parameters to use when establishing the consultation call. This parameter can be set to **NULL** if no special call setup parameters are desired.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding LINE_REPLY message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_BEARERMODEUNAVAIL, LINEERR_UNINITIALIZED, LINEERR_CALLUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_CONFERENCEFULL, LINEERR_INVALPOINTER, LINEERR_INUSE, LINEERR_INVALRATE, LINEERR_INVALADDRESSMODE, LINEERR_NOMEM, LINEERR_INVALBEARERMODE, LINEERR_NOTOWNER, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLPARAMS, LINEERR_RATEUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALLINESTATE, LINEERR_STRUCTURETOOSMALL, LINEERR_USERUSERINFOTOOBIG.

## Remarks

If LINEERR_INVALLINESTATE is returned, the line is currently not in a state in which this operation can be performed. A list of currently valid operations can be found in the **dwLineFeatures** member (of the type
[LINEFEATURE](https://learn.microsoft.com/windows/desktop/Tapi/linefeature--constants)) in the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure. (Calling
[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus) updates the information in
**LINEDEVSTATUS**.) If LINEERR_INVALMEDIAMODE is returned, check for supported media types on the line in the **dwMediaModes** member in the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

The
**lineSetupConference** function provides two ways to establish a new conference call, depending on whether a normal two-party call is required to pre-exist or not. When setting up a conference call from an existing two-party call, the *hCall* parameter is a valid call handle that is initially added to the conference call by the
**lineSetupConference** request; *hLine* is ignored. On switches where conference call setup does not start with an existing call, *hCall* must be **NULL** and *hLine* must be specified to identify the line device on which to initiate the conference call. In either case, a consultation call is allocated for connecting to the party that is to be added to the call. The application can then use
[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial) to dial the address of the other party.

The conference call typically transitions into the *onHoldPendingConference* state, the consultation call into the *dialtone* state, and the initial call (if there is one) into the *conferenced* state.

A conference call can also be set up by a
[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer) that is resolved into a three-way conference. The application may be able to toggle between the consultation call and the conference call using
[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold).

A consultation call can be canceled by invoking
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop) on it. When dropping a consultation call, the existing conference call typically transitions back to the *connected* state. The application should observe the LINE_CALLSTATE messages to determine exactly what happens to the calls. For example, if the conference call reverts back to a regular two-party call, the conference call becomes idle and the original participant call can revert to *connected*.

If an application specifies the handle of the original call (*hCall*) in a call to the
[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold) function, both the conference call and the consultation call typically go to idle.

> [!NOTE]
> The tapi.h header defines lineSetupConference as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Conference overview](https://learn.microsoft.com/windows/desktop/Tapi/conference-ovr)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer)

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus)

[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold)

[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold)