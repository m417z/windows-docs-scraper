# WTSWaitSystemEvent function

## Description

Waits for a Remote Desktop Services event before returning to the caller.

## Parameters

### `hServer` [in]

Handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify WTS_CURRENT_SERVER_HANDLE to indicate the RD Session Host server on which your application is running.

### `EventMask` [in]

Bitmask that specifies the set of events to wait for. This mask can be WTS_EVENT_FLUSH to cause all pending
**WTSWaitSystemEvent** calls on the specified RD Session Host server handle to return. Or, the mask can be a combination of the following values.

#### WTS_EVENT_ALL

Wait for any event type.

#### WTS_EVENT_CONNECT

A client connected to a WinStation.

#### WTS_EVENT_CREATE

A new WinStation was created.

#### WTS_EVENT_DELETE

An existing WinStation was deleted.

#### WTS_EVENT_DISCONNECT

A client disconnected from a WinStation.

#### WTS_EVENT_LICENSE

The Remote Desktop Services' license state changed. This occurs when a license is added or deleted using
License Manager.

#### WTS_EVENT_LOGOFF

A user logged off from either the Remote Desktop Services console or from a client WinStation.

#### WTS_EVENT_LOGON

A user logged on to the system from either the Remote Desktop Services console or from a client WinStation.

#### WTS_EVENT_RENAME

An existing WinStation was renamed.

#### WTS_EVENT_STATECHANGE

A WinStation connection state changed. For a list of connection states, see the
[WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class) enumeration
type.

### `pEventFlags` [out]

Pointer to a variable that receives a bitmask of the event or events that occurred. The returned mask can
be a combination of the values from the previous list, or it can be **WTS_EVENT_NONE** if
the wait terminated because of a **WTSWaitSystemEvent** call with
**WTS_EVENT_FLUSH**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)