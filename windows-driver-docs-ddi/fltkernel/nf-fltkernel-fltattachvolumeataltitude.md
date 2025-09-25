# FltAttachVolumeAtAltitude function

## Description

**FltAttachVolumeAtAltitude** is a debugging support routine that attaches a minifilter driver instance to a volume at a specified altitude, overriding any settings in the minifilter driver's INF file.

## Parameters

### `Filter` [in, out]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `Volume` [in, out]

Opaque volume pointer for the volume that the minifilter driver instance is to be attached to. This parameter is required and cannot be **NULL**.

### `Altitude` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the altitude string for the instance. This parameter is required and cannot be **NULL**. (For more information about this parameter, see the following Remarks section.)

### `InstanceName` [in, optional]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the instance name for the new instance. This parameter is optional and can be **NULL**. If it is **NULL**, **FltAttachVolumeAtAltitude** generates an instance name from the minifilter driver name and the altitude string that *Altitude* points to. The generated name is truncated, if necessary, to INSTANCE_NAME_MAX_CHARS characters.

### `RetInstance` [out, optional]

Pointer to a caller-allocated variable that receives an opaque instance pointer for the newly created instance. This parameter is optional and can be **NULL**.

## Return value

**FltAttachVolumeAtAltitude** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The specified *Filter* or *Volume* is being torn down. This is an error code. |
| **STATUS_FLT_FILTER_NOT_READY** | The minifilter driver has not started filtering. For more information, see [FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering). This is an error code. |
| **STATUS_FLT_INSTANCE_ALTITUDE_COLLISION** | An instance already exists at this altitude on the volume specified. This is an error code. |
| **STATUS_FLT_INSTANCE_NAME_COLLISION** | An instance already exists with this name on the volume specified. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltAttachVolumeAtAltitude** encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_PARAMETER** | The UNICODE_STRING structure that *Altitude* points to did not contain a valid altitude string. This is an error code. |

## Remarks

A minifilter driver should only use **FltAttachVolumeAtAltitude** for debugging. It should not call this routine in a retail version of the minifilter driver.

**FltAttachVolumeAtAltitude** is the kernel equivalent of the Win32 [FilterAttachAtAltitude](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterattachataltitude) function.

The term "altitude" refers to the position that an instance occupies (or should occupy) in the minifilter driver instance stack for a volume. The higher the altitude, the farther the instance is from the base file system in the stack. Only one instance can be attached at a given altitude on a given volume.

Altitude is specified by an *altitude string*, which is a wide-character array containing one or more decimal digits from 0 through 9; the array can include a single decimal point. For example, "100.123456" and "03333" are valid altitude strings.

The string "03333" represents a higher altitude than "100.123456" (Leading and trailing zeros are ignored.) In other words, an instance whose altitude is "03333" is farther from the base file system than an instance whose altitude is "100.123456". However, this comparison is only meaningful if both instances are attached to the same volume.

The instance name specified in the *InstanceName* parameter is required to be unique across the system.

**FltAttachVolumeAtAltitude** returns an opaque instance pointer for the new instance in **RetInstance*. This pointer value uniquely identifies the minifilter driver instance and remains constant as long as the instance is attached to the volume.

**FltAttachVolumeAtAltitude** adds a rundown reference to the opaque instance pointer returned in **RetInstance*. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltAttachVolumeAtAltitude** must be matched by a subsequent call to **FltObjectDereference**.

To compare the altitudes of two minifilter driver instances attached to the same volume, call [FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes).

To detach a minifilter driver instance from a volume, call [FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume).

## See also

[FilterAttachAtAltitude](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterattachataltitude)

[FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume)

[FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes)

[FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume)

[FltGetVolumeInstanceFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinstancefromname)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)