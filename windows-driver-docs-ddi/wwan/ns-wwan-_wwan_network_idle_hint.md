# _WWAN_NETWORK_IDLE_HINT structure

## Description

The WWAN_NETWORK_IDLE_HINT structure contains a hint for the network interface regarding whether data is expected to be active or idle on the interface.

## Members

### `IsEnabled`

If TRUE, this is a hint that the network interface should utilize mechanisms for entering lower power modes faster. If FALSE, it is a hint that the network interface not utilize mechanisms for entering lower power modes faster.

## See also

[NDIS_WWAN_NETWORK_IDLE_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_network_idle_hint)

[OID_WWAN_NETWORK_IDLE_HINT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-idle-hint)