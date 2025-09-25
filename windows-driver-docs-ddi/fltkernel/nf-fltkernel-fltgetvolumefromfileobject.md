# FltGetVolumeFromFileObject function

## Description

The **FltGetVolumeFromFileObject** routine returns an opaque pointer for the volume that a given file stream resides on.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for a file stream that resides on the volume.

### `RetVolume` [out]

Pointer to a caller-allocated variable that receives an opaque pointer for the volume. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeFromFileObject** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The volume is being torn down. This is an error code. |
| **STATUS_INVALID_PARAMETER** | No matching volume was found. This is an error code. |

## Remarks

**FltGetVolumeFromFileObject** adds a rundown reference to the opaque volume pointer returned in the *RetVolume* parameter. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetVolumeFromFileObject** must be matched by a subsequent call to **FltObjectDereference**.

To get a pointer to the device object for a given volume, call [FltGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject).

## See also

[FltGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject)

[FltGetDiskDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdiskdeviceobject)

[FltGetVolumeFromDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)