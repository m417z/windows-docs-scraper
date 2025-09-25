# RAS_CONNECTION_2 structure

## Description

The
**RAS_CONNECTION_2** structure contains information for a connection, including the Globally Unique Identifier (GUID) that identifies the connection.

## Members

### `hConnection`

A handle to the connection.

### `wszUserName`

A null-terminated Unicode string that contains the name of the user logged on to the connection.

### `dwInterfaceType`

A [ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type) enumeration that identifies the type of connection interface.

### `guid`

A GUID that identifies the connection. For incoming connections, this GUID is valid only as long as the connection is active.

### `PppInfo2`

A
[PPP_INFO_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info_2) structure that contains Point-to-Point (PPP) projection operation information for a connection.

## See also

[MprAdminAcceptReauthentication](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthentication)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminConnectionHangupNotification3](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification3)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)