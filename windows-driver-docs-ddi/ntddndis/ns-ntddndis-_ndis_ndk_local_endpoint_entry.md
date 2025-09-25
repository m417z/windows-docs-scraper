# _NDIS_NDK_LOCAL_ENDPOINT_ENTRY structure

## Description

The **NDIS_NDK_LOCAL_ENDPOINT_ENTRY** structure specifies an ND local endpoint entry for an ND local endpoint on a miniport adapter.

## Members

### `Local`

The local IP address and port.

### `UserModeOwner`

A BOOLEAN value that is TRUE if the connection is an NDS user-mode connection, or FALSE if it is an NDK kernel-mode connection.

### `Listener`

A BOOLEAN value that is TRUE if the connection is a listener or FALSE if it is a shared endpoint.

### `OwnerPid`

A process identifier for an NDS user-mode connection.

## Remarks

The NDIS_NDK_LOCAL_ENDPOINT_ENTRY structure is used in the [NDIS_NDK_LOCAL_ENDPOINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_local_endpoints) structure to specify an array of local endpoints.

## See also

[NDIS_NDK_LOCAL_ENDPOINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_local_endpoints)