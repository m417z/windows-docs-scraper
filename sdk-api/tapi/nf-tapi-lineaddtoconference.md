# lineAddToConference function

## Description

The
**lineAddToConference** function adds the call specified by *hConsultCall* to the conference call specified by *hConfCall*.

## Parameters

### `hConfCall`

Handle to the conference call. The application must be an owner of this call. Any monitoring (media, tones, digits) on a conference call applies only to the *hConfCall*, not to the individual participating calls. Call state of *hConfCall* must be *onHoldPendingConference* or *onHold*.

### `hConsultCall`

Handle to the call to be added to the conference call. The application must be an owner of this call. This call cannot be a parent of another conference or a participant in any conference. Depending on the device capabilities indicated in
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps), the *hConsultCall* may not necessarily have been established using
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference) or
[linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineprepareaddtoconference). The call state of *hConsultCall* must be *connected*, *onHold*, *proceeding*, or *ringback*. Many PBXs allow calls to be added to conferences before they are actually answered.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds, or it is a negative error number if an error occurs. Possible return values are:

LINEERR_CONFERENCEFULL, LINEERR_NOTOWNER, LINEERR_INVALCONFCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

If LINEERR_INVALCALLHANDLE is returned, the specified call handle for the added call is invalid; *hConsultCall* is a parent of another conference or already a participant in a conference; *hConsultCall* cannot be added for other reasons (such as, it must have been established using
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference) or
[linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineprepareaddtoconference)); or *hConsultCall* and *hConfCall* are calls on different open lines.

The call handle of the added party remains valid after adding the call to a conference. Its state typically changes to *conferenced* while the state of the conference call typically becomes *connected*. Using
[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls), you can obtain a list of call handles that are part of the same conference call as the specified call. The specified call is either a conference call or a participant call in a conference call. New handles are generated for those calls for which the application does not already have handles, and the application is granted monitor privilege to those calls. The handle to an individual participating call can be used later to remove that party from the conference call using
[lineRemoveFromConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineremovefromconference).

If
[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls) is called immediately after
**lineAddToConference**, it may not return a complete list of related calls because TAPI waits to receive a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message indicating that the call has entered LINECALLSTATE_CONFERENCED before it considers the call to actually be part of the conference (that is, the conferenced state is confirmed by the service provider). After the application has received the LINE_CALLSTATE message,
[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls) returns complete information.

**Note** All calls that are part of a conference must exist on the same open line.

The call states of the calls participating in a conference are not independent. For example, when dropping a conference call, all participating calls can automatically become idle. An application should consult the line's device capabilities to determine what form of conference removal is available. The application should track the LINE_CALLSTATE messages to determine what happened to the calls involved.

The conference call is established either by
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference) or
[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer). The call added to a conference is typically established using
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference) or
[linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineprepareaddtoconference). Some switches can allow adding arbitrary calls to the conference, and such a call can have been set up using
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) and be on (hard) hold. The application can examine the **dwAddrCapFlags** member of the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) structure to determine the permitted operations.

## See also

[Conference overview](https://learn.microsoft.com/windows/desktop/Tapi/conference-ovr)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer)

[lineGetConfRelatedCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetconfrelatedcalls)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineprepareaddtoconference)

[lineRemoveFromConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineremovefromconference)

[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference)