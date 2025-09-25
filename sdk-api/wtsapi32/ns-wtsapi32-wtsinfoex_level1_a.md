# WTSINFOEX_LEVEL1_A structure

## Description

Contains extended information about a Remote Desktop Services session.

## Members

### `SessionId`

The session identifier.

### `SessionState`

A value of the [WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class) enumeration type that specifies the connection state of a Remote Desktop Services session.

### `SessionFlags`

The state of the session. This can be one or more of the following values.

#### WTS_SESSIONSTATE_UNKNOWN (4294967295 (0xFFFFFFFF))

The session state is not known.

#### WTS_SESSIONSTATE_LOCK (0 (0x0))

The session is locked.

#### WTS_SESSIONSTATE_UNLOCK (1 (0x1))

The session is unlocked.

**Windows Server 2008 R2 and Windows 7:** Due to a code defect, the usage of the **WTS_SESSIONSTATE_LOCK** and **WTS_SESSIONSTATE_UNLOCK** flags is reversed. That is, **WTS_SESSIONSTATE_LOCK** indicates that the session is unlocked, and **WTS_SESSIONSTATE_UNLOCK** indicates the session is locked.

### `WinStationName`

A null-terminated string that contains the name of the window station for the session.

### `UserName`

A null-terminated string that contains the name of the user who owns the session.

### `DomainName`

A null-terminated string that contains the name of the domain that the user belongs to.

### `LogonTime`

The time that the user logged on to the session. This value is stored as a large integer that represents the number of 100-nanosecond intervals since January 1, 1601 Coordinated Universal Time (Greenwich Mean Time).

### `ConnectTime`

The time of the most recent client connection to the session. This value is stored as a large integer that represents the number of 100-nanosecond intervals since January 1, 1601 Coordinated Universal Time.

### `DisconnectTime`

The time of the most recent client disconnection to the session. This value is stored as a large integer that represents the number of 100-nanosecond intervals since January 1, 1601 Coordinated Universal Time.

### `LastInputTime`

The time of the last user input in the session. This value is stored as a large integer that represents the number of 100-nanosecond intervals since January 1, 1601 Coordinated Universal Time.

### `CurrentTime`

The time that this structure was filled. This value is stored as a large integer that represents the number of 100-nanosecond intervals since January 1, 1601 Coordinated Universal Time.

### `IncomingBytes`

The number of bytes of uncompressed Remote Desktop Protocol (RDP) data sent from the client to the server since the client connected.

### `OutgoingBytes`

The number of bytes of uncompressed RDP data sent from the server to the client since the client connected.

### `IncomingFrames`

The number of frames of RDP data sent from the client to the server since the client connected.

### `OutgoingFrames`

The number of frames of RDP data sent from the server to the client since the client connected.

### `IncomingCompressedBytes`

The number of bytes of compressed RDP data sent from the client to the server since the client connected.

### `OutgoingCompressedBytes`

The number of bytes of compressed RDP data sent from the server to the client since the client connected.

## See also

[WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class)