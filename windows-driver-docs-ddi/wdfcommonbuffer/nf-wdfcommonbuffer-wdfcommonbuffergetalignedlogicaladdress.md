# WdfCommonBufferGetAlignedLogicalAddress function

## Description

[Applies to KMDF only]

The **WdfCommonBufferGetAlignedLogicalAddress** method returns the logical address that is associated with a specified common buffer.

## Parameters

### `CommonBuffer` [in]

A handle to a common buffer object that the driver obtained by a previous call to [WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate).

## Return value

**WdfCommonBufferGetAlignedLogicalAddress** returns the logical address of the buffer that is associated with the common buffer that the *CommonBuffer* parameter specifies.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Logical addresses are mapped addresses that devices use to access physical memory.

If the driver called [WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement) to set a buffer alignment requirement, the framework aligns the common buffer according to that alignment requirement.

For more information about common buffers, see [Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers)

#### Examples

For a code example that uses **WdfCommonBufferGetAlignedLogicalAddress**, see [WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate).

## See also

[WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate)

[WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress)

[WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement)