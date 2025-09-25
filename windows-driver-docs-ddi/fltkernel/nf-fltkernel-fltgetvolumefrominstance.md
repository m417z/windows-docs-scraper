# FltGetVolumeFromInstance function

## Description

The **FltGetVolumeFromInstance** routine returns an opaque pointer for the volume that a given minifilter driver instance is attached to.

## Parameters

### `Instance` [in]

Opaque instance pointer for the instance.

### `RetVolume` [out]

Pointer to a caller-allocated variable that receives an opaque pointer for the volume. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeFromInstance** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The volume that the minifilter driver instance is attached to is being torn down. This is an error code. |

## Remarks

**FltGetVolumeFromInstance** adds a rundown reference to the opaque volume pointer returned in the *RetVolume* parameter. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetVolumeFromInstance** must be matched by a subsequent call to **FltObjectDereference**.

To get an opaque filter pointer for the minifilter driver that created a given instance, call [FltGetFilterFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterfrominstance).

To get a pointer to the device object for a given volume, call [FltGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject).

To get detailed information about the volume that a given instance is attached to, call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation).

## See also

[FltGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdeviceobject)

[FltGetFilterFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterfrominstance)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)