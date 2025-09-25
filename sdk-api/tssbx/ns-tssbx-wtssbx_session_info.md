# WTSSBX_SESSION_INFO structure

## Description

Contains information about sessions that are available to Remote Desktop Connection Broker (RD Connection Broker).

## Members

### `wszUserName`

The user name that is associated with the session. The name cannot exceed 104 characters.

### `wszDomainName`

The domain name of the user. The name cannot exceed 256 characters.

### `ApplicationType`

The name of the program that should be run after the session is created. The name cannot exceed 256 characters.

### `dwSessionId`

The session identifier.

### `CreateTime`

The time that the session was initiated.

### `DisconnectTime`

The time that the user disconnected from the session.

### `SessionState`

A value of the [WTSSBX_SESSION_STATE](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_session_state) enumeration type that indicates the state of the session.

## See also

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)