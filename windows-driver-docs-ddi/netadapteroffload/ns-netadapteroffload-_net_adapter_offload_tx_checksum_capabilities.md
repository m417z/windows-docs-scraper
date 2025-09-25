# _NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES structure

## Description

The **NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES** structure describes a network interface card (NIC)'s Tx checksum offload capabilities.

## Members

### `Size`

The size of this structure in bytes.

### `Layer3Flags`

Flags specifying the layer 3 protocol variations that the NIC can successfully perform Tx checksum on.

The flags should be a combination of:

| Flag | Description |
| --- | --- |
| NetAdapterOffloadLayer3FlagIPv4NoOptions | Set if the NIC is capable of performing IPv4 checksum offload or TCP/UDP checksum offload on IPv4 packets without options |
| NetAdapterOffloadLayer3FlagIPv4WithOptions | Set if the NIC is capable of performing Tx checksum offload on IPv4 packets with options |
| NetAdapterOffloadLayer3FlagIPv6NoExtensions | Set if the NIC is capable of performing Tx checksum offload on IPv6 packets without extensions |
| NetAdapterOffloadLayer3FlagIPv6WithExtensions | Set if the NIC is capable of performing Tx checksum offload on IPv6 packets with extensions |

### `Layer4Flags`

Flags specifying the layer 4 protocol variations that the NIC can successfully perform Tx checksum on. This member is optional.

The flags should be a combination of:

| Flag | Description |
| --- | --- |
| NetAdapterOffloadLayer4FlagTcpNoOptions | Set if the NIC is capable of performing TCP checksum offload |
| NetAdapterOffloadLayer4FlagTcpWithOptions | Set if the NIC is capable of performing Tx checksum offload on TCP packets with options |
| NetAdapterOffloadLayer4FlagUdp | Set if the NIC is capable of performing UDP checksum offload |

### `Layer3HeaderOffsetLimit`

The maximum layer 3 header offset that the NIC supports in bytes. This member is optional.

### `Layer4HeaderOffsetLimit`

The maximum layer 4 header offset that the NIC supports in bytes. This member is optional.

### `EvtAdapterOffloadSetTxChecksum`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_TX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_tx_checksum) callback function.

## Remarks

Call [**NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_tx_checksum_capabilities_init) to initialize this structure. The client driver passes an initialized **NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES** structure as a parameter to [**NetAdapterOffloadSetTxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsettxchecksumcapabilities).

## See also

[Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_TX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_tx_checksum)

[**NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_tx_checksum_capabilities_init)

[**NetAdapterOffloadSetTxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsettxchecksumcapabilities)