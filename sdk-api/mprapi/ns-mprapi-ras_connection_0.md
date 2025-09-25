# RAS_CONNECTION_0 structure

## Description

The
**RAS_CONNECTION_0** structure contains general information regarding a specific connection, such as user name or domain. For more detailed information about a specific connection, such as bytes sent or received, see
[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1).

## Members

### `hConnection`

A handle to the connection.

### `hInterface`

A handle to the interface.

### `dwConnectDuration`

A value that represent the duration of the connection, in seconds.

### `dwInterfaceType`

A [ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type) enumeration that identifies the type of connection interface.

### `dwConnectionFlags`

A bitmap of flags that specify connection attributes. **dwConnectionFlags** must contain at least one of the following values:

| Value | Meaning |
| --- | --- |
| **RAS_FLAGS_PPP_CONNECTION**<br><br>0x00000001 | The connection is using Point-to-Point Protocol (PPP). |
| **RAS_FLAGS_MESSENGER_PRESENT**<br><br>0x00000002 | The messenger service is active on the client and messages can be sent to the client using [MprAdminSendUserMessage](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminsendusermessage). |
| **RAS_FLAGS_QUARANTINE_PRESENT**<br><br>0x00000008 | The connection is currently in quarantine. For information on how to remove the connection from quarantine, please see [MprAdminConnectionRemoveQuarantine](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionremovequarantine). |
| **RAS_FLAGS_ARAP_CONNECTION**<br><br>0x00000010 | The connection is using AppleTalk Remote Access Protocol (ARAP). |
| **RAS_FLAGS_IKEV2_CONNECTION**<br><br>0x00000010 | The connection is using IKEv2. |
| **RAS_FLAGS_DORMANT**<br><br>0x00000020 | The connection is using IKEv2 and the server is not reachable. |

### `wszInterfaceName`

 A null-terminated Unicode string that contains the name of the interface for this connection.

### `wszUserName`

A null-terminated Unicode string that contains the name of the user logged on to the connection.

### `wszLogonDomain`

A null-terminated Unicode string that contains the domain on which the connected user is authenticated.

### `wszRemoteComputer`

A null-terminated Unicode string that contains the name of the remote computer.

## See also

[MprAdminAcceptReauthentication](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthentication)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminConnectionHangupNotification3](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification3)

[RAS
Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)