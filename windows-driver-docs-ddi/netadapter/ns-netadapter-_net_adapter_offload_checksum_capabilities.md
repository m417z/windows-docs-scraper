# _NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES structure

## Description

> [!NOTE]
> The **NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES** function is deprecated in NetAdapterCx 2.1 and later. For more information on current checksum offload functions, see [Checksum offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload).

The **NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES** structure describes a network interface card (NIC)'s capabilities for offloading checksum calculation and validation.

## Members

### `Size`

The size of this structure, in bytes.

### `IPv4`

A flag specifying whether the NIC can calculate and validate IPv4 checksum.

### `Tcp`

A flag specifying whether the NIC can calculate and validate TCP checksum.

### `Udp`

A flag specifying whether the NIC can calculate and validate UDP checksum.

### `EvtAdapterOffloadSetChecksum`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_offload_set_checksum) callback function.

## Remarks

Call [**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_offload_checksum_capabilities_init) to initialize this structure. An initialized **NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES** structure is passed as a parameter to [**NetAdapterOffloadSetChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteroffloadsetchecksumcapabilities).

## See also

[NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads)

[**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_offload_checksum_capabilities_init)

[**NetAdapterOffloadSetChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteroffloadsetchecksumcapabilities)