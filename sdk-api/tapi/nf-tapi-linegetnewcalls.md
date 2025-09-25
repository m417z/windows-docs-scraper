# lineGetNewCalls function

## Description

The
**lineGetNewCalls** function returns call handles to calls on a specified line or address for which the application currently does not have handles. The application is granted monitor privilege to these calls.

## Parameters

### `hLine`

Handle to an open line device.

### `dwAddressID`

Address on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwSelect`

Selection of calls that are requested. This parameter uses one and only one of the
[LINECALLSELECT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `lpCallList`

Pointer to a variably sized data structure of type
[LINECALLLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecalllist). Upon successful completion of the request, call handles to all selected calls are returned in this structure. Prior to calling
**lineGetNewCalls**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSELECT, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

An application can use
**lineGetNewCalls** to obtain handles to calls for which it currently has no handles. The application can select the calls for which handles are to be returned by basing this selection on scope (calls on a specified line, or calls on a specified address). For example, an application can request call handles to all calls on a given address for which it currently has no handle. The application is always given monitor privilege to the new call handles. Also, when opening a line, an application uses this function to become aware of existing calls.

The application can invoke
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo) and
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus) for each call in the list to determine the call's information and status, respectively. It can use
[lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege) to change its privilege to owner.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINECALLLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecalllist)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)

[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus)

[lineSetCallPrivilege](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallprivilege)