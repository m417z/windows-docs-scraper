# NET_IF_MEDIA_DUPLEX_STATE enumeration

## Description

The NET_IF_MEDIA_DUPLEX_STATE enumeration type specifies the
[NDIS network interface](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-network-interfaces2) duplex
state.

## Constants

### `MediaDuplexStateUnknown`

The duplex state of the miniport adapter is unknown.

### `MediaDuplexStateHalf`

The miniport adapter can transmit or receive but not both simultaneously.

### `MediaDuplexStateFull`

The miniport adapter can transmit and receive simultaneously.

## Remarks

The NDIS_MEDIA_DUPLEX_STATE, enumeration type, used to describe NDIS interface providers in the
OID_GEN_MEDIA_DUPLEX_STATE, OID, is equivalent to this enumeration.

```
typedef NET_IF_MEDIA_DUPLEX_STATE NDIS_MEDIA_DUPLEX_STATE, *PNDIS_MEDIA_DUPLEX_STATE;
```