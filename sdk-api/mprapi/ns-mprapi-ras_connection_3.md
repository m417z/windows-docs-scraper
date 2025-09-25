# RAS_CONNECTION_3 structure

## Description

The
**RAS_CONNECTION_3** structure contains information for the connection, including the Globally Unique Identifier (GUID) that identifies the connection and the quarantine state of the connection.

## Members

### `dwVersion`

The version of the **RAS_CONNECTION_3** structure used.

### `dwSize`

The size, in bytes, of this **RAS_CONNECTION_3** structure.

### `hConnection`

A handle to the connection.

### `wszUserName`

A null-terminated Unicode string that contains the name of the user logged on to the connection.

### `dwInterfaceType`

A [ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type) enumeration that identifies the type of connection interface.

### `guid`

A GUID that identifies the connection. For incoming connections, this GUID is valid only as long as the connection is active.

### `PppInfo3`

A
[PPP_INFO_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info_3) structure that contains Point-to-Point (PPP) projection operation information for a connection.

### `rasQuarState`

A [RAS_QUARANTINE_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-ras_quarantine_state) structure that specifies the Network Access Protection (NAP) quarantine state of the connection.

### `timer`

A FILETIME structure that specifies the time required for the connection to come out of quarantine after which the connection will be dropped. This value is valid only if **rasQuarState** has a value of **RAS_QUAR_STATE_PROBATION**.

## See also

[MprAdminAcceptReauthentication](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthentication)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminConnectionHangupNotification3](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification3)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)