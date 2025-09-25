# FltDetachVolume function

## Description

**FltDetachVolume** detaches a minifilter driver instance from a volume.

## Parameters

### `Filter` [in, out]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `Volume` [in, out]

Opaque volume pointer for the volume where the instance is attached. This parameter is required and cannot be **NULL**.

### `InstanceName` [in, optional]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the instance name for the instance to be removed. This parameter is optional and can be **NULL**. If it is **NULL**, the highest matching instance is removed.

## Return value

**FltDetachVolume** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | **FltDetachVolume** found a matching instance, but the instance is being torn down. This is an error code. |
| **STATUS_FLT_INSTANCE_NOT_FOUND** | No matching instance was found. This is an error code. |

## Remarks

**FltDetachVolume** detaches a minifilter driver instance from a volume and tears down the instance.

To attach a minifilter driver instance to a volume, call [FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume) or [FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude).

To compare the altitudes of two minifilter driver instances attached to the same volume, call [FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes).

## See also

[FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume)

[FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude)

[FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes)

[FltGetVolumeInstanceFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinstancefromname)