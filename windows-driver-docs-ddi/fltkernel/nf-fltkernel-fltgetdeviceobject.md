# FltGetDeviceObject function

## Description

The **FltGetDeviceObject** routine returns a pointer to the Filter Manager's volume device object (VDO) for a given volume.

## Parameters

### `Volume` [in]

Opaque pointer for the volume.

### `DeviceObject` [out]

Pointer to a caller-allocated variable that receives the volume device object pointer. This parameter is required and cannot be **NULL**.

## Return value

**FltGetDeviceObject** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_NO_DEVICE_OBJECT | The requested device object does not exist for the given volume. This is an error code. |

## Remarks

**FltGetDeviceObject** returns a pointer to the Filter Manager's volume device object (VDO) for the given volume.

For more information about volume device objects, see [File System Stacks](https://learn.microsoft.com/windows-hardware/drivers/ifs/storage-device-stacks--storage-volumes--and-file-system-stacks#file-system-stacks).

The Filter Manager's VDO is not the same as the underlying storage driver's disk device object or the base file system's VDO. To get a pointer to the disk device object, call [**FltGetDiskDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdiskdeviceobject) on the volume specified in the *Volume* parameter. To get a pointer to the base file system's VDO, call [**IoGetDeviceAttachmentBaseRef**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdeviceattachmentbaseref) on the *RetDeviceObject* returned by **FltGetDeviceObject**.

To get an opaque pointer for the corresponding volume for a given device object, call [**FltGetVolumeFromDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject).

**FltGetDeviceObject** increments the reference count on the returned device object pointer. When this pointer is no longer needed, the caller must decrement this reference count by calling [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject). Thus every successful call to **FltGetDeviceObject** must be matched by a subsequent call to **ObDereferenceObject**.

## See also

[**FltGetDiskDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdiskdeviceobject)

[**FltGetVolumeFromDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject)

[**IoGetDeviceAttachmentBaseRef**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdeviceattachmentbaseref)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)