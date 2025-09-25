# FltGetDiskDeviceObject function

## Description

The **FltGetDiskDeviceObject** routine returns a pointer to the disk device object associated with a given volume.

## Parameters

### `Volume` [in]

Opaque pointer for the volume. This parameter is required and cannot be **NULL**.

### `DiskDeviceObject` [out]

Pointer to a caller-allocated variable that receives the device object pointer. On any error, this parameter is not modified.

## Return value

**FltGetDiskDeviceObject** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_NO_DEVICE_OBJECT | The requested device object does not exist for the given volume. This is an error code. |

## Remarks

**FltGetDiskDeviceObject** retrieves a pointer to the storage device object for the physical disk where the volume resides. The storage device need not be an actual disk.

**FltGetDiskDeviceObject** increments the reference count on the device object pointer returned in **DiskDeviceObject**. When this pointer is no longer needed, the caller must decrement this reference count by calling [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject). Failure to do so prevents the system from freeing or deleting the device object because of the outstanding reference. Thus every successful call to **FltGetDiskDeviceObject** must be matched by a subsequent call to **ObDereferenceObject**.

A minifilter must call **FltGetDiskDeviceObject** only in an I/O related callback. Otherwise, the fields of the device object returned may not be valid. This the case in callback routines such as [**InstanceTeardownStartCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback) and **InstanceTeardownCompleteCallback**.

To get a pointer to the Filter Manager's volume device object (VDO) for a given volume, call [**FltGetDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject).

To get an opaque volume pointer for the volume represented by a volume device object, call [**FltGetVolumeFromDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject).

For more information about volume device objects, see [File System Stacks](https://learn.microsoft.com/windows-hardware/drivers/ifs/storage-device-stacks--storage-volumes--and-file-system-stacks#file-system-stacks).

## See also

[**FltGetDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject)

[**FltGetVolumeFromDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[**ObReferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobject)