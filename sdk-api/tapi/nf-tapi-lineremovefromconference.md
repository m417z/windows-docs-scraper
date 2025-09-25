# lineRemoveFromConference function

## Description

The
**lineRemoveFromConference** function removes the specified call from the conference call to which it currently belongs. The remaining calls in the conference call are unaffected.

## Parameters

### `hCall`

Handle to the call to be removed from the conference. The application must be an owner of this call. The call state of *hCall* must be *conferenced*.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED.

## Remarks

This operation removes a party that currently belongs to a conference call. After the call has been successfully removed, it may be possible to further manipulate it using its handle. The availability of this operation and its result are likely to be limited in many implementations. For example, in many implementations, only the most recently added party can be removed from a conference, and the removed call can be automatically dropped (becomes idle). Consult the line's device capabilities to determine the available effects of removing a call from a conference.

If the removal of a participant from a conference is supported, the participant call, after it is removed from the conference, enters the call-state listed in the **dwRemoveFromConfState** member in
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps).

## See also

[Conference overview](https://learn.microsoft.com/windows/desktop/Tapi/conference-ovr)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)