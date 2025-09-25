# NetDmaRegisterProvider function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaRegisterProvider** function registers a DMA provider.

## Parameters

### `ProviderContext` [in]

A pointer to a block of driver-allocated context information that stores information about the DMA
provider. NetDMA passes the context information in subsequent calls to
*Provider*Xxx functions that required a DMA provider context.

### `pNetDmaProviderHandle` [in]

A pointer to a value that is a handle that
**NetDmaRegisterProvider** supplies to identify the DMA provider. The DMA provider driver passes this
handle to
**NetDma*Xxx*** functions that require a provider handle.

### `ProviderCharacteristics` [in]

A pointer to a
[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics) structure that defines the characteristics of the DMA
provider.

## Return value

**NetDmaRegisterProvider** can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

DMA provider drivers call the
**NetDmaRegisterProvider** function to register a DMA provider. DMA provider drivers call
**NetDmaRegisterProvider** in their
[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

In the
**AddDevice** routine, the DMA provider driver calls the
[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) function to create a functional
device object (FDO) and inserts it at the top of the device stack. The DMA provider driver then calls
**NetDmaRegisterProvider** to register the associated DMA provider.

The DMA provider driver supplies a
[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics) structure at the
*ProviderCharacteristics* parameter of
**NetDmaRegisterProvider**. The NET_DMA_PROVIDER_CHARACTERISTICS structure specifies the
characteristics for a NetDMA provider, including the entry points for the
*ProviderXxx* functions.

The DMA provider driver provides a pointer to a block of driver-allocated context information at the
*ProviderContext* parameter of
**NetDmaRegisterProvider**. This context area stores information about the DMA provider. The NetDMA
interface passes the context information in subsequent calls to
*ProviderXxx* functions that require a DMA provider context.

When
**NetDmaRegisterProvider** returns, it provides a handle at the location that the
*pNetDmaProviderHandle* parameter specifies. The NetDMA interface assigns this handle to identify the
DMA provider. The DMA provider driver uses this handle in all subsequent calls to
**NetDma*Xxx*** functions that are associated with the DMA provider.

If a computer supports MSI-X, the NetDMA interface, while in the context of the
**NetDmaRegisterProvider** function, calls the DMA provider driver's
[ProviderSetDmaChannelCpuAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channels_cpu_affinity_handler) function to specify the CPU affinity of the interrupt for each DMA
channel.

If a computer supports MSI-X, the DMA provider driver can specify interrupt affinities while handling
the
[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) IRP. After the
[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine successfully returns, the Plug
and Play (PnP) manager sends the IRP_MN_FILTER_RESOURCE_REQUIREMENTS IRP for the DMA provider. The DMA
provider driver must attempt to allocate MSI-X interrupt resources according to affinity parameters that
the NetDMA interface passed to
*ProviderSetDmaChannelCpuAffinity*.

To deregister a DMA provider, a DMA provider driver calls the
[NetDmaDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaderegisterprovider) function.

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics)

[NetDmaDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaderegisterprovider)

[ProviderSetDmaChannelCpuAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channels_cpu_affinity_handler)