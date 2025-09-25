# _NET_DMA_PROVIDER_ATTRIBUTES structure

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The NET_DMA_PROVIDER_ATTRIBUTES structure specifies the configuration attributes for a NetDMA
provider.

## Members

### `MajorHwVersion`

The major version number of the DMA provider hardware.

### `MinorHwVersion`

The minor version number of the DMA provider hardware.

### `Size`

The size, in bytes, of this NET_DMA_PROVIDER_ATTRIBUTES structure. Set this member to
sizeof(NET_DMA_PROVIDER_ATTRIBUTES).

### `Flags`

Reserved for DMA provider attributes flags. Set this member to zero.

### `VendorId`

A vendor identifier (ID) that uniquely identifies the vendor that created the DMA engine. This
vendor ID is specified in the device's PCI configuration space. For more information about the vendor
ID, see
[Identifiers for PCI
Devices](https://learn.microsoft.com/windows-hardware/drivers/install/identifiers-for-pci-devices).

### `DmaChannelCount`

The number of DMA channels that the DMA provider supports. This number can differ from the
**MaxDmaChannelCount** member of the
[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics) structure that defines the maximum number of DMA channels that
this type of DMA provider can support.

### `MaximumTransferSize`

The maximum DMA transfer size, in bytes, that the DMA provider can support. This value can must be
4 KB or greater.

### `MaximumAddressSpace`

The largest physical address that the DMA engine can support.

## Remarks

To start a DMA provider, the DMA provider driver supplies a NET_DMA_PROVIDER_ATTRIBUTES structure at
the
*ProviderAttributes* parameter of the
[NetDmaProviderStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstart) function.

A DMA provider driver initializes a DMA engine and starts a DMA provider while handling the
[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRP.

## See also

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics)

[NetDmaProviderStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstart)

[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop)