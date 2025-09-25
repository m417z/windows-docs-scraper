# WTSINFOW structure

## Description

Contains information about a Remote Desktop Services session.

## Members

### `State`

A value of the [WTS_CONNECTSTATE_CLASS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ne-wtsapi32-wts_connectstate_class) enumeration type that indicates the session's current connection state.

### `SessionId`

The session identifier.

### `IncomingBytes`

Uncompressed Remote Desktop Protocol (RDP) data from the client to the server.

### `OutgoingBytes`

Uncompressed RDP data from the server to the client.

### `IncomingFrames`

The number of frames of RDP data sent from the client to the server since the client connected.

### `OutgoingFrames`

The number of frames of RDP data sent from the server to the client since the client connected.

### `IncomingCompressedBytes`

Compressed RDP data from the client to the server.

### `OutgoingCompressedBytes`

Compressed RDP data from the server to the client.

### `WinStationName`

A null-terminated string that contains the name of the WinStation for the session.

### `Domain`

A null-terminated string that contains the name of the domain that the user belongs to.

### `UserName`

A null-terminated string that contains the name of the user who owns the session.

### `ConnectTime`

The most recent client connection time.

### `DisconnectTime`

The last client disconnection time.

### `LastInputTime`

The time of the last user input in the session.

### `LogonTime`

The time that the user logged on to the session.

### `CurrentTime`

The time that the **WTSINFO** data structure was called.

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).