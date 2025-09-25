# lineGetConfRelatedCalls function

## Description

The
**lineGetConfRelatedCalls** function returns a list of call handles that are part of the same conference call as the specified call. The specified call is either a conference call or a participant call in a conference call. New handles are generated for those calls for which the application does not already have handles, and the application is granted monitor privilege to those calls.

## Parameters

### `hCall`

Handle to a call. This is either a conference call or a participant call in a conference call. For a conference parent call, the call state of *hCall* can be any state. For a conference participant call, it must be in the *conferenced* state.

### `lpCallList`

Pointer to a variably sized data structure of type
[LINECALLLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecalllist). Upon successful completion of the request, call handles to all calls in the conference call are returned in this structure. The first call in the list is the conference call, the other calls are the participant calls. The application is granted monitor privilege to those calls for which it does not already have handles; the privileges to calls in the list for which the application already has handles is unchanged. Prior to calling
**lineGetConfRelatedCalls**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOCONFERENCE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

The specified call can either be a conference call handle or a handle to a participant call. For example, a consultation call that has not yet been added to a conference call is not part of a conference. The first entry in the list that is returned is the conference call handle, the other handles are all the participant calls. The specified call is always one of the calls returned in the list. Calls in the list to which the application does not already have a call handle are assigned monitor privilege; privileges to calls for which the application already has handles are unchanged. The application can use
[lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege) to change the privilege of the call.

If
**lineGetConfRelatedCalls** is called immediately after a call is added to a conference using
[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer),
**lineGetConfRelatedCalls** may not return a complete list of related calls because TAPI waits to receive a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message indicating that the call has entered LINECALLSTATE_CONFERENCED before it considers the call to actually be part of the conference (that is, the *conferenced* state is confirmed by the service provider). After the application has received the LINE_CALLSTATE message,
**lineGetConfRelatedCalls** returns complete information.

The application can invoke
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo) and
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus) for each call in the list to determine the call's information and status, respectively.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linecompletetransfer)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)

[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus)

[lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege)