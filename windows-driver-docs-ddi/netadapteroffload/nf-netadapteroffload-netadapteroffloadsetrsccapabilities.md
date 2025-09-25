# NetAdapterOffloadSetRscCapabilities function

## Description

The **NetAdapterOffloadSetRscCapabilities** function sets the hardware receive segment coalescence (RSC) offload capabilities of a network adapter.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `HardwareCapabilities` [_In_]

A pointer to a driver-allocated and initialized [**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities) structure that describes the hardware's RSC offload capabilities.

## Remarks

Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Receive Segment Coalescing offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities)

[**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_rsc_capabilities_init)

[*EVT_NET_ADAPTER_OFFLOAD_SET_RSC*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)