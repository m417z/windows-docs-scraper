# _NDIS_NDK_CONNECTION_ENTRY structure

## Description

The **NDIS_NDK_CONNECTION_ENTRY** structure specifies a connection entry for an active NDK connection on a miniport adapter.

## Members

### `Local`

The local IP address and port.

### `Remote`

The remote IP address and port.

### `UserModeOwner`

A BOOLEAN value that is TRUE if the connection is an NDS user-mode connection, or FALSE if it is an NDK kernel-mode connection.

### `OwnerPid`

A process identifier for an NDS user-mode connection.

## Remarks

The NDIS_NDK_CONNECTION_ENTRY structure is used in the [NDIS_NDK_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_connections) structure to specify an array of connections.

## See also

[NDIS_NDK_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_connections)