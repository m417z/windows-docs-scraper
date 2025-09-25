# _ISCSI_Path structure

## Description

The ISCSI_Path structure contains information about a connection of the iSCSI portal.

## Members

### `UniqueConnectionId`

This is a unique connection identifier that the initiator uses to identify a connection. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the UniqueConnectionId parameter. This value is not to be confused with the connection ID (CID).

### `EstimatedLinkSpeed`

This specifies the connection speed in megabits per second (Mbps).

### `PathWeight`

This specifies the weight assigned to this path. The value can be any 32-bit number, with a higher number that signifies a higher priority. If more than one path is available, this path weight value is compared against each other path weight and will be prioritized accordingly. For example, if a value of 1 is used for path1 and a value of 2 for path2, path2 has higher priority.

### `PrimaryPath`

This specifies the state of the path: primary or secondary. If the value is 1, it means the path is the primary path, and if it is 0, it is a secondary path.

### `ConnectionStatus`

This indicates the status of the connection.

| Type | Meaning |
| --- | --- |
| CONNECTION_STATE_CONNECTED (1) | The path is connected and active. |
| CONNECTION_STATE_DISCONNECTED (2) | The path is disconnected. |
| CONNECTION_STATE_RECONNECTING(3) | The path is reconnecting. |

### `TCPOffLoadAvailable`

This indicates whether the connection supports TCP offload or not.

## Remarks

The iSCSI headers and MOF are included in the platform SDK and WDK.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)