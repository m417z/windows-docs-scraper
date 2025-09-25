# FltGetVolumeFromDeviceObject function

## Description

The **FltGetVolumeFromDeviceObject** routine returns an opaque pointer for the volume represented by a volume device object (VDO).

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `DeviceObject` [in]

Pointer to the volume device object.

### `RetVolume` [out]

Pointer to a caller-allocated variable that receives an opaque pointer for the volume. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeFromDeviceObject** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_DELETING_OBJECT | The volume is being torn down. This is an error code. |
| STATUS_INVALID_PARAMETER | Volume device object specified in the *DeviceObject* parameter was not a valid volume device object pointer, or no matching volume was found. This is an error code. |

## Remarks

The *DeviceObject* parameter can be a pointer to a filter or a file system volume device object (VDO). If it points to a storage device object, **FltGetVolumeFromDeviceObject** returns STATUS_INVALID_PARAMETER.

For more information about volume device objects, see [File System Stacks](https://learn.microsoft.com/windows-hardware/drivers/ifs/storage-device-stacks--storage-volumes--and-file-system-stacks#file-system-stacks).

**FltGetVolumeFromDeviceObject** adds a rundown reference to the opaque volume pointer returned in the *RetVolume* parameter. When this pointer is no longer needed, the caller must release it by calling [**FltObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetVolumeFromDeviceObject** must be matched by a subsequent call to **FltObjectDereference**.

To get a pointer to the device object for a given volume, call [**FltGetDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject).

## See also

[**FltGetDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject)

[**FltGetDiskDeviceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdiskdeviceobject)

[**FltObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)