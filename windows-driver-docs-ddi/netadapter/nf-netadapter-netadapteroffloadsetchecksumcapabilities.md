# NetAdapterOffloadSetChecksumCapabilities function

## Description

> [!NOTE]
> The **NetAdapterOffloadSetChecksumCapabilities** function is deprecated in NetAdapterCx 2.1 and later. For more information on current checksum offload functions, see [Checksum offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload).

The **NetAdapterOffloadSetChecksumCapabilities** function sets the hardware checksum offload capabilities of a network adapter.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `HardwareCapabilities` [_In_]

A pointer to a driver-allocated and initialized [**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities) structure that describes the hardware's checksum offload capabilities.

## Remarks

Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[NetAdapterCx hardware offloads](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-hardware-offloads)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_offload_checksum_capabilities)

[**NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_offload_checksum_capabilities_init)

[*EVT_NET_ADAPTER_OFFLOAD_SET_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_offload_set_checksum)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)