# NET_IF_MEDIA_CONNECT_STATE enumeration

## Description

The NET_IF_MEDIA_CONNECT_STATE enumeration type specifies the
[NDIS network interface](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-network-interfaces2) connection
state.

## Constants

### `MediaConnectStateUnknown`

The connection state of the interface is unknown.

### `MediaConnectStateConnected`

The interface is connected to the network.

### `MediaConnectStateDisconnected`

The interface is not connected to the network.

## Remarks

The NDIS_MEDIA_CONNECT_STATE enumeration type, used to describe NDIS interface providers in the
OID_GEN_MEDIA_CONNECT_STATUS_EX OID, is equivalent to this enumeration.

```
typedef NET_IF_MEDIA_CONNECT_STATE NDIS_MEDIA_CONNECT_STATE, *PNDIS_MEDIA_CONNECT_STATE;
```