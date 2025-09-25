# EvtOpenSession function

## Description

Establishes a connection to a remote computer that you can use when calling the other Windows Event Log functions.

## Parameters

### `LoginClass` [in]

The connection method to use to connect to the remote computer. For possible values, see the [EVT_LOGIN_CLASS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_login_class) enumeration.

### `Login` [in]

A [EVT_RPC_LOGIN](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_rpc_login) structure that identifies the remote computer that you want to connect to, the user's credentials, and the type of authentication to use when connecting.

### `Timeout` [in]

Reserved. Must be zero.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a session handle that you can use to access event log information on the remote computer; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

When you are finished with the session handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function. Closing the session handle will also close all open handles created in the session (closing the open handles cancels any current activity on those handles).

To connect to the remote computer, the remote computer must enable the "Remote Event Log Management" Windows Firewall exception; otherwise, when you try to use the session handle, the call will error with RPC_S_SERVER_UNAVAILABLE. The computer to which you are connecting must be running Windows Vista or later.

This function does not validate the credentials; the credentials are validated the first time you try to use the session handle. If the credentials are not valid, the call will fail with ERROR_ACCESS_DENIED.

#### Examples

For an example that shows how to use this function, see [Accessing Remote Computers](https://learn.microsoft.com/windows/desktop/WES/accessing-remote-computers).

## See also

[EVT_LOGIN_CLASS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_login_class)

[EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose)