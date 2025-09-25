# ISCSI_CONNECTION_INFOA structure

## Description

The **ISCSI_CONNECTION_INFO** structure contains information about a connection.

## Members

### `ConnectionId`

A ISCSI_UNIQUE_CONNECTION_ID structure that contains the unique identifier for a connection. The LoginIScsiTarget and AddIScsiConnection functions return this value via the UniqueConnectionId parameter.

### `InitiatorAddress`

A string that represents the IP address of the initiator.

### `TargetAddress`

A string that represents the IP address of the target.

### `InitiatorSocket`

The socket number on the initiator that establishes the connection.

### `TargetSocket`

The socket number on the target that establishes the connection.

### `CID`

The connection identifier for the connection.

## See also

[ISCSI_UNIQUE_CONNECTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb870817(v=vs.85))

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_CONNECTION_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).