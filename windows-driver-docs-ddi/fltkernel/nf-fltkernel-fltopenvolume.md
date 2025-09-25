# FltOpenVolume function

## Description

The **FltOpenVolume** routine returns a handle and a file object pointer for the file system volume that a given minifilter driver instance is attached to.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance. This instance must be attached to a local volume.

### `VolumeHandle` [out]

Handle for the file system volume.

### `VolumeFileObject` [out]

Pointer to a caller-allocated variable that receives a file object pointer for the root directory of the volume. This parameter is optional and can be **NULL**.

## Return value

**FltOpenVolume** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The instance or volume is being torn down. This is an error code. |
| **STATUS_INVALID_PARAMETER** | The instance is attached to a network volume. This is an error code. |

## Remarks

When the handle returned in the *VolumeHandle* parameter is no longer needed, the caller must release it by calling [FltClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclose). Thus every successful call to **FltOpenVolume** must be matched by a subsequent call to **FltClose**.

If a file object pointer is returned in the *VolumeFileObject* parameter, the caller must release it when it is no longer needed by calling [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject).

The instance specified by the *Instance* parameter must be attached to a local volume. If it is attached to a network volume, **FltOpenVolume** returns STATUS_INVALID_PARAMETER.

To get a pointer to the device object for a given volume, call [FltGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject).

To get detailed information about the volume that a given instance is attached to, call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation).

NOTE: Do not call this routine with a non-NULL top level IRP value, as this can cause a system deadlock. To determine if the thread TopLevelIrp is set call [IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp).

## See also

[FltClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclose)

[FltGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject)

[FltGetFilterFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterfrominstance)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)