# _SetTunnelModeOuterAddress_IN structure

## Description

The SetTunnelModeOuterAddress_IN structure holds the input data for the [SetTunnelModeOuterAddress](https://learn.microsoft.com/windows-hardware/drivers/storage/settunnelmodeouteraddress) method.

## Members

### `PortNumber`

The number of the port to associate with the tunnel-mode address. A value of 0xffffffff associates the tunnel-mode address with all ports.

### `DestinationAddress`

An [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that indicates the destination IP address in a way that is independent of the version of IP protocol in use.

### `TunnelModeOuterAddress`

An ISCSI_IP_Address structure that indicates the IP address of the security gateway (tunnel-mode outer address) in a way that is independent of the version of IP protocol in use.

## Remarks

You must implement this method.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[SetTunnelModeOuterAddress](https://learn.microsoft.com/windows-hardware/drivers/storage/settunnelmodeouteraddress)

[SetTunnelModeOuterAddress_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_settunnelmodeouteraddress_out)