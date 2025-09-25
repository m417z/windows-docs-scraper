# lineSetCallPrivilege function

## Description

The
**lineSetCallPrivilege** function sets the application's privilege to the specified privilege.

## Parameters

### `hCall`

Handle to the call whose privilege is to be set. The call state of *hCall* can be any state.

### `dwCallPrivilege`

Required privilege for the specified call. This parameter uses one and only one of the
[LINECALLPRIVILEGE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallprivilege--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCALLPRIVILEGE, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

If the application is the sole owner of a non-idle call and can change its privilege to monitor, a LINEERR_INVALCALLSTATE error is returned. The application can also first drop the call using
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop) to make the call transition to the *idle* state and then change its privilege.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)