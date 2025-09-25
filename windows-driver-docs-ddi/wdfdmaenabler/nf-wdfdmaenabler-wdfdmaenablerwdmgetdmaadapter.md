# WdfDmaEnablerWdmGetDmaAdapter function

## Description

[Applies to KMDF only]

The **WdfDmaEnablerWdmGetDmaAdapter** method returns a pointer to a WDM [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure that is associated with a DMA enabler object.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained from a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

### `DmaDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value that specifies the direction of the DMA transfer operation. For more information, see the following Remarks section.

## Return value

**WdfDmaEnablerWdmGetDmaAdapter** returns a pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure, or **NULL** if the *DmaDirection* parameter's value is invalid.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

When your driver calls [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate), the framework creates a separate [adapter object](https://learn.microsoft.com/windows-hardware/drivers/kernel/adapter-objects-and-dma) for each direction if the driver specifies a duplex profile, and it creates a single adapter object if the driver does not specify a duplex profile.

If your driver specified a duplex profile when it called [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate), the **WdfDmaEnablerWdmGetDmaAdapter** method's *DmaDirection* parameter's value must be **WdfDmaDirectionReadFromDevice** to obtain the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure for read operations and **WdfDmaDirectionWriteToDevice** to obtain the **DMA_ADAPTER** structure for write operations. If your driver did not specify a duplex profile, the driver can specify either **WdfDmaDirectionReadFromDevice** or **WdfDmaDirectionWriteToDevice**.

The pointer that **WdfDmaEnablerWdmGetDmaAdapter** returns is valid until the DMA enabler object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the DMA enabler object, the pointer is valid until the callback function returns.

#### Examples

The following code example creates a DMA enabler object and then obtains pointers to the WDM [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structures that the framework creates for read and write operations.

```cpp
NTSTATUS  status = STATUS_SUCCESS;
WDF_DMA_ENABLER_CONFIG  dmaConfig;
WDFDMAENABLER  dmaEnabler;
PDMA_ADAPTER  readAdapter, writeAdapter;

WDF_DMA_ENABLER_CONFIG_INIT(
                            &dmaConfig,
                            WdfDmaProfileScatterGatherDuplex,
                            maxLength
                            );
status = WdfDmaEnablerCreate(
                             Device,
                             &dmaConfig,
                             WDF_NO_OBJECT_ATTRIBUTES,
                             &dmaEnabler
                             );
if (!NT_SUCCESS (status)) {
    return status;
}

readAdapter = WdfDmaEnablerWdmGetDmaAdapter(
                                            dmaEnabler,
                                            WdfDmaDirectionReadFromDevice
                                            );
writeAdapter = WdfDmaEnablerWdmGetDmaAdapter(
                                             dmaEnabler,
                                             WdfDmaDirectionWriteToDevice
                                             );
```

## See also

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)