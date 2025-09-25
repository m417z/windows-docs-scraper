# PCONFIGURE_ADAPTER_CHANNEL callback function

## Description

The **ConfigureAdapterChannel** routine invokes a custom function that is implemented by the DMA controller represented by an adapter object.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `FunctionNumber` [in]

The number of the custom function to select. For more information, see the Remarks section.

### `Context` [in]

A pointer to the configuration parameters for the custom function that is specified by *FunctionNumber*. The function is implemented by the DMA controller and can be accessed by a device driver through the adapter object. The DMA controller and the device driver must agree on the meaning of these configuration parameters. The data that *Context* points to is opaque to the operating system.

## Return value

**ConfigureAdapterChannel** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status code.

| Return value | Description |
| --- | --- |
| STATUS_NOT_IMPLEMENTED | The DMA extension does not implement the function specified by *FunctionNumber*. |

## Remarks

**ConfigureAdapterChannel** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

Use **ConfigureAdapterChannel** only for system DMA adapters. Do not use this routine for a bus-master adapter.

A particular system DMA controller might have special hardware features that device drivers can access through a set of one or more custom functions. A controller might implement more than one custom function, in which case each function is identified by a different function number. These functions abstract the DMA hardware features so that the same functions can be supported on different hardware platforms.

Typically, a custom function sets state information in the DMA controller to configure hardware features for use in subsequent DMA transfers.

## See also

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)