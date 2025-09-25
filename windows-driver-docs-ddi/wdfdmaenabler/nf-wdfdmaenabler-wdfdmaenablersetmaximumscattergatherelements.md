# WdfDmaEnablerSetMaximumScatterGatherElements function

## Description

[Applies to KMDF only]

The **WdfDmaEnablerSetMaximumScatterGatherElements** method sets the maximum number of scatter/gather elements that a device supports, for a specified DMA enabler object.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained from a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

### `MaximumFragments` [in]

The maximum number of scatter/gather elements that the driver and device can support.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If your driver calls **WdfDmaEnablerSetMaximumScatterGatherElements**, it must do so within the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) or [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function.

If your driver does not call **WdfDmaEnablerSetMaximumScatterGatherElements**, the framework uses a default value of WDF_DMA_ENABLER_UNLIMITED_FRAGMENTS, which means that there is no limit to the number of scatter/gather elements.

For more information about this method, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions).

#### Examples

The following code example sets the maximum number of scatter/gather elements for a specified DMA enabler object.

```cpp
WdfDmaEnablerSetMaximumScatterGatherElements(
                                             DmaEnabler,
                                             NIC_MAX_PHYS_BUF_COUNT
                                             );
```

## See also

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaEnablerGetMaximumScatterGatherElements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablergetmaximumscattergatherelements)