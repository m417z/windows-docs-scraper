# WdfDmaEnablerGetFragmentLength function

## Description

[Applies to KMDF only]

The **WdfDmaEnablerGetFragmentLength** method returns the maximum transfer length that the operating system supports for a single [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers).

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained from a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

### `DmaDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value that specifies the direction of the DMA transfer operation. For more information, see the following Remarks section.

## Return value

**WdfDmaEnablerGetFragmentLength** returns the maximum length of a DMA transfer, in bytes, that the operating system can support, or zero if the *DmaDirection* parameter's value is invalid.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The maximum DMA transfer length that the operating system can support depends on the number of [map registers](https://learn.microsoft.com/windows-hardware/drivers/kernel/map-registers) that are available. If enough map registers are available, **WdfDmaEnablerGetFragmentLength** returns the same value that [WdfDmaEnablerGetMaximumLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablergetmaximumlength) returns. Otherwise, the value that **WdfDmaEnablerGetFragmentLength** returns will be less than the value that **WdfDmaEnablerGetMaximumLength** returns.

Your driver can determine the number of map registers that are available by using the BYTE_TO_PAGES macro, as follows:

```cpp
BYTE_TO_PAGES(WdfDmaEnablerGetFragmentLength()) + 1
```
If your driver specified a duplex profile when it called [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate), the *DmaDirection* parameter's value must be **WdfDmaDirectionReadFromDevice** to obtain the maximum transfer length for read operations and **WdfDmaDirectionWriteToDevice** to obtain the maximum transfer length for write operations. If your driver did not specify a duplex profile, the driver can specify either **WdfDmaDirectionReadFromDevice** or **WdfDmaDirectionWriteToDevice** for *DmaDirection*.

Note that if your driver's device supports duplex operation, **WdfDmaEnablerGetFragmentLength** can return different values for the read and write directions that the *DmaDirection* parameter specifies. This difference is because the framework creates a separate [adapter object](https://learn.microsoft.com/windows-hardware/drivers/kernel/adapter-objects-and-dma) for each direction, and the operating system might provide a different number of map registers to each adapter object.

#### Examples

The following code example determines the minimum number of map registers that are necessary to handle a NIC device's read operations, calculates the number of map registers that are available, and reports an error if the number of allocated map registers is insufficient.

```cpp
ULONG  minimumMapRegisters;
ULONG  maxLengthSupported;
ULONG  mapRegistersAllocated;

miniMapRegisters = BYTES_TO_PAGES(NIC_MAX_PACKET_SIZE) + 1;

maxLengthSupported =
    (ULONG) WdfDmaEnablerGetFragmentLength(
                                           FdoData->WdfDmaEnabler,
                                           WdfDmaDirectionReadFromDevice
                                           );

mapRegistersAllocated = BYTES_TO_PAGES(maxLengthSupported) + 1;

if (mapRegistersAllocated < minimumMapRegisters) {
    status = STATUS_INSUFFICIENT_RESOURCES;
    return status;
}
```

## See also

[WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaEnablerGetMaximumLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablergetmaximumlength)