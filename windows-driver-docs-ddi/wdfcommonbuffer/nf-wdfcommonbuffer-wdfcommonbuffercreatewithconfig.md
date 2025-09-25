# WdfCommonBufferCreateWithConfig function

## Description

[Applies to KMDF only]

The **WdfCommonBufferCreateWithConfig** method creates a memory buffer that both the driver and a direct memory access (DMA) device can access simultaneously, and the method also specifies buffer configuration information.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained by a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

### `Length` [in]

The desired size, in bytes, of the new buffer.

### `Config` [in]

A pointer to a [WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config) structure that contains configuration information about the buffer.

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the common buffer object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `CommonBuffer` [out]

A pointer to a WDFCOMMONBUFFER-typed variable that receives a handle to a common buffer object.

## Return value

**WdfCommonBufferCreateWithConfig** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The driver supplied an invalid parameter. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate a common buffer object, or the system could not allocate a buffer. |

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfCommonBufferCreateWithConfig** method allocates memory and maps it so that both the driver and a device can access it simultaneously for DMA operations.

Additionally, **WdfCommonBufferCreateWithConfig** enables your driver to specify a buffer alignment requirement for the buffer. The buffer alignment requirement overrides the buffer alignment requirement that the driver specified when it called [WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement). Your driver can use **WdfCommonBufferCreateWithConfig**, instead of [WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate), if you want the driver to create a buffer that has a different alignment requirement than the one that **WdfDeviceSetAlignmentRequirement** specified.

After your driver calls **WdfCommonBufferCreateWithConfig**, the driver must:

* Call [WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress) to obtain the buffer's virtual address, which the driver can use.
* Call [WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress) to obtain the buffer's logical address, which the device can use.

A driver typically calls **WdfCommonBufferCreateWithConfig** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

The operating system determines whether to enable cached memory in the common buffer that is to be allocated. That decision is based on the processor architecture and device bus.

On computers with x86-based, x64-based, and Itanium-based processors, cached memory is enabled.
On computers with ARM or ARM 64-based processors, the operating system does not automatically enable cached memory for all devices. The system relies on the ACPI_CCA method for each device to determine whether the device is cache-coherent.

For more information about common buffers, see [Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers)

#### Examples

The following code example initializes a [WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config) structure and then creates a 10-byte buffer that is aligned on a 32-byte boundary.

```cpp
WDF_COMMON_BUFFER_CONFIG  commonBufConfig;
WDFCOMMONBUFFER  commonBuffer;

WDF_COMMON_BUFFER_CONFIG_INIT(
                              &commonBufConfig,
                              FILE_32_BYTE_ALIGNMENT
                              );

status = WdfCommonBufferCreateWithConfig(
                                         DmaEnabler,
                                         10,
                                         &commonBufConfig,
                                         WDF_NO_OBJECT_ATTRIBUTES,
                                         &commonBuffer
                                         );
if (!NT_SUCCESS (status)) {
    return status;
}
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate)

[WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress)

[WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress)

[WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)