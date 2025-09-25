# WdfCommonBufferCreate function

## Description

[Applies to KMDF only]

The **WdfCommonBufferCreate** method creates a memory buffer that both the driver and a direct memory access (DMA) device can access simultaneously.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained by a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

### `Length` [in]

The desired size, in bytes, of the new buffer. The maximum allowed buffer size is (MAXULONG - PAGE_SIZE) bytes.

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the common buffer object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `CommonBuffer` [out]

A pointer to a WDFCOMMONBUFFER-typed variable that receives a handle to a common buffer object.

## Return value

**WdfCommonBufferCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplied an invalid parameter. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate a common buffer object, or the system could not allocate a buffer. |

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfCommonBufferCreate** method allocates memory and maps it so that both the driver and a device can access it simultaneously for DMA operations. After your driver calls **WdfCommonBufferCreate**, the driver must:

* Call [WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress) to obtain the buffer's virtual address, which the driver can use.
* Call [WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress) to obtain the buffer's logical address, which the device can use.

A driver typically calls **WdfCommonBufferCreate** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

Before the driver calls [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate), it can call [WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement) to set a buffer alignment requirement. If the driver does not call **WdfDeviceSetAlignmentRequirement**, buffers are aligned on word boundaries. If your driver creates multiple DMA enablers, each with a different buffer alignment requirement, the driver can call **WdfDeviceSetAlignmentRequirement** before each call to **WdfDmaEnablerCreate**.

To create a common buffer that has an alignment requirement that is different from the alignment requirement that the driver specified with [WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement), the driver can call [WdfCommonBufferCreateWithConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreatewithconfig) instead of **WdfCommonBufferCreate**.

The operating system determines whether to enable cached memory in the common buffer that is to be allocated. That decision is based on the processor architecture and device bus.

On computers with x86-based, x64-based, and Itanium-based processors, cached memory is enabled.
On computers with ARM or ARM 64-based processors, the operating system does not automatically enable cached memory for all devices. The system relies on the ACPI_CCA method for each device to determine whether the device is cache-coherent.

The DMA enabler object that the *DmaEnabler* parameter of **WdfCommonBufferCreate** specifies becomes the parent object for the new common buffer object. The driver cannot change this parent, and the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**. The framework deletes each common buffer object when it deletes the parent DMA enabler object. Alternatively, you can delete the common buffer object explicitly by calling [**WdfObjectDelete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete).

For more information about common buffers, see [Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers).

#### Examples

The following code example shows how to obtain a common buffer. The example stores information about the common buffer in driver-defined context space that is identified by the **DevExt** pointer.

```cpp
DevExt->CommonBufferSize = sizeof(COMMON_BUFFER_STRUCT);  // Your structure size
status = WdfCommonBufferCreate(
                               DevExt->DmaEnabler,
                               DevExt->CommonBufferSize,
                               WDF_NO_OBJECT_ATTRIBUTES,
                               &DevExt->CommonBuffer
                               );
if (status == STATUS_SUCCESS) {
    DevExt->CommonBufferBaseVA =
        WdfCommonBufferGetAlignedVirtualAddress(DevExt->CommonBuffer);
    DevExt->CommonBufferBaseLA =
        WdfCommonBufferGetAlignedLogicalAddress(DevExt->CommonBuffer);
}
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfCommonBufferCreateWithConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreatewithconfig)

[WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress)

[WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress)

[WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)