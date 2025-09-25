# WTS_CONNECTSTATE_CLASS enumeration

## Description

Specifies the connection state of a Remote Desktop Services session.

## Constants

### `WTSActive`

A user is logged on to the WinStation. This state occurs when a user is signed in and actively connected to the device.

### `WTSConnected`

The WinStation is connected to the client.

### `WTSConnectQuery`

The WinStation is in the process of connecting to the client.

### `WTSShadow`

The WinStation is shadowing another WinStation.

### `WTSDisconnected`

The WinStation is active but the client is disconnected. This state occurs when a user is signed in but not actively connected to the device, such as when the user has chosen to exit to the lock screen.

### `WTSIdle`

The WinStation is waiting for a client to connect.

### `WTSListen`

The WinStation is listening for a connection. A listener session waits for requests for new client connections. No user is logged on a listener session. A listener session cannot be reset, shadowed, or changed to a regular client session.

### `WTSReset`

The WinStation is being reset.

### `WTSDown`

The WinStation is down due to an error.

### `WTSInit`

The WinStation is initializing.

## See also

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

[WTSWaitSystemEvent](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtswaitsystemevent)

[WTS_SESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_infoa)