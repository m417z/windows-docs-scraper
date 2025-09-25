# NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT function

## Description

> [!NOTE]
> The **NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT** function is deprecated in NetAdapterCx 2.1 and later. For more information on current checksum offload functions, see [Checksum offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload).

The **NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities) structure.

## Parameters

### `ChecksumCapabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities) structure.

### `IPv4` [_In_]

A flag specifying whether the hardware can calculate and validate IPv4 checksum.

### `Tcp` [_In_]

A flag specifying whether the hardware can calculate and validate TCP checksum.

### `Udp` [_In_]

A flag specifying whether the hardware can calculate and validate UDP checksum.

### `EvtAdapterOffloadSetChecksum` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_offload_set_checksum) callback function.

## Remarks

The [**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities) structure initialized by this function is passed as a parameter to the [**NetAdapterOffloadSetChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapteroffloadsetchecksumcapabilities) function.

## See also

[NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads)

[**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities)