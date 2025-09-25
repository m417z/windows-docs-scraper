# _KSMAPPING structure

## Description

The KSMAPPING structure is used to describe a single contiguous chunk of physical memory for use in scatter/gather DMA operations.

## Members

### `PhysicalAddress`

This member contains the physical address of this piece of the data frame.

### `ByteCount`

This member contains the number of bytes of contiguous physical memory in this individual mapping.

### `Alignment`

This member specifies the memory alignment in bytes for this buffer.

## Remarks

In order for minidrivers to use this structure within the stream pointer offsets, the pin for which this is referring must specify scatter/gather DMA mapping generation through KSPIN_FLAG_GENERATE_MAPPINGS and the client must register its DMA adapter object with AVStream using **KsDeviceRegisterAdapterObject**. See [AVStream DMA Services](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-dma-services). The KSPIN_FLAG_GENERATE_MAPPINGS flag is defined on the [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex) reference page.

## See also

[KSSTREAM_POINTER_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer_offset)

[KsDeviceRegisterAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteradapterobject)