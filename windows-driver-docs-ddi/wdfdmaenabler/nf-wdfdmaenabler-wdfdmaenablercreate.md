# WdfDmaEnablerCreate function

## Description

[Applies to KMDF only]

The **WdfDmaEnablerCreate** method creates a DMA enabler object.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Config` [in]

A pointer to a [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure. Drivers must initialize this structure by calling [WDF_DMA_ENABLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_enabler_config_init).

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the new DMA enabler object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `DmaEnablerHandle` [out]

A handle to a new DMA enabler object.

## Return value

**WdfDmaEnablerCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to construct a new DMA enabler object. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure is incorrect. |
| **STATUS_NOT_SUPPORTED** | The driver requested DMA version 3 on an operating system earlier than Windows 8. |

For a list of other return values that the **WdfDmaEnablerCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Framework-based drivers must call **WdfDmaEnablerCreate** before creating DMA transactions for a device.

Before a driver calls **WdfDmaEnablerCreate**, it must call [WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement).

The framework device object that the *Device* parameter of **WdfDmaEnablerCreate** specifies always becomes the parent object for the new DMA enabler object. If the driver specifies a different parent in the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, the framework ignores this value. The framework deletes the DMA enabler object when it deletes the parent object.

When called with a *Config* parameter that requests a system-mode DMA profile, **WdfDmaEnablerCreate** creates a partially initialized DMA enabler. The driver must subsequently call [WdfDmaEnablerConfigureSystemProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerconfiguresystemprofile) to set up the DMA settings for the underlying channels.

For more information about DMA enabler objects and **WdfDmaEnablerCreate**, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions).

#### Examples

The following code example is from the [PLX9x5x](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example sets a device's requirement for buffer alignment, initializes a WDF_DMA_ENABLER_CONFIG structure, and calls **WdfDmaEnablerCreate**.

```cpp
//
// PLx PCI9656 DMA_TRANSFER_ELEMENTS must be 16-byte aligned.
//
WdfDeviceSetAlignmentRequirement(
                                 DevExt->WdfDevice,
                                 PCI9656_DTE_ALIGNMENT_16
                                 );

//
// Create a new DMA enabler object instance.
// Use scatter/gather, 64-bit addresses, and duplex-type profile.
//
{
    WDF_DMA_ENABLER_CONFIG   dmaConfig;
    WDF_DMA_ENABLER_CONFIG_INIT(
                                &dmaConfig,
                                WdfDmaProfileScatterGather64Duplex,
                                DevExt->MaximumTransferLength
                                );
    status = WdfDmaEnablerCreate(
                                 DevExt->WdfDevice,
                                 &dmaConfig,
                                 WDF_NO_OBJECT_ATTRIBUTES,
                                 &DevExt->DmaEnabler
                                 );
    if (!NT_SUCCESS (status)) {
        // Cannot continue, so release device resources.
        return status;
    }
}
```

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WDF_DMA_ENABLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_enabler_config_init)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement)