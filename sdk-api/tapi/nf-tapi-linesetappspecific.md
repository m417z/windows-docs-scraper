# lineSetAppSpecific function

## Description

The
**lineSetAppSpecific** function enables an application to set the application-specific field of the specified call's call-information record.

## Parameters

### `hCall`

Handle to the call whose application-specific field needs to be set. The application must be an owner of the call. The call state of *hCall* can be any state.

### `dwAppSpecific`

New content of the **dwAppSpecific** member for the call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure. This value is not interpreted by the Telephony API.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_NOTOWNER, LINEERR_OPERATIONUNAVAIL, LINEERR_OPERATIONFAILED.

## Remarks

The application-specific field in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) data structure that exists for each call is not interpreted by the Telephony API or any of its service providers. Its usage is entirely defined by the applications. The field can be read from the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) record returned by
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo). However,
**lineSetAppSpecific** must be used to set the field so that changes become visible to other applications. When this field is changed, all other applications with call handles are sent a LINE_CALLINFO message with an indication that the **dwAppSpecific** member has changed.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)