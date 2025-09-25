# WdfDmaEnablerGetMaximumScatterGatherElements function

## Description

[Applies to KMDF only]

The **WdfDmaEnablerGetMaximumScatterGatherElements** method returns the maximum number of scatter/gather elements that the device and driver support, for a specified DMA enabler object.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained from a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

## Return value

If the driver previously called [WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements), **WdfDmaEnablerGetMaximumScatterGatherElements** returns the value that the driver specified in the previous call. Otherwise, **WdfDmaEnablerGetMaximumScatterGatherElements** returns WDF_DMA_ENABLER_UNLIMITED_FRAGMENTS, which indicates that there is no limit to the number of scatter/gather elements.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about this method, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions).

#### Examples

The following code example obtains the maximum number of scatter/gather elements for a specified DMA enabler object.

```cpp
size_t maxElements;

maxElements = WdfDmaEnablerGetMaximumScatterGatherElements(DmaEnabler);

```

## See also

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaEnablerSetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablersetmaximumscattergatherelements)