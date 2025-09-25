# FltGetVolumeInstanceFromName function

## Description

The **FltGetVolumeInstanceFromName** routine returns an opaque instance pointer for the given minifilter driver instance on the given volume.

## Parameters

### `Filter` [in, optional]

Opaque filter pointer for the minifilter driver that owns the instance. This parameter is optional and can be **NULL**.

### `Volume` [in]

Opaque pointer for the volume that the instance is attached to. Must be a valid volume handle. This parameter is required and cannot be **NULL**. (Setting this parameter to an invalid value causes the system to ASSERT on a checked build.)

### `InstanceName` [in, optional]

Pointer to a caller-allocated [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the instance name for the instance on the volume. (This is the *InstanceName* value that was passed to [FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume) or [FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude) when the instance was created.) This parameter is optional and can be **NULL**. If it is **NULL**, **FltGetVolumeInstanceFromName** returns the highest matching instance that is found.

### `RetInstance` [out]

Pointer to a caller-allocated variable that receives an opaque instance pointer for the instance that matches the values for *Filter*, *Volume*, and *InstanceName*. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeInstanceFromName** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The instance is being torn down. This is an error code. |
| **STATUS_FLT_INSTANCE_NOT_FOUND** | No matching instance was found. This is an error code. |

## Remarks

**FltGetVolumeInstanceFromName** searches the list of minifilter driver instances attached to the volume specified in the *Volume* parameter in order of decreasing altitude, beginning with the topmost instance. If more than one instance matches the given values for the *Filter*, *Volume*, and *InstanceName* parameters, **FltGetVolumeInstanceFromName** returns the highest matching instance that is found.

The term "altitude" refers to the position that an instance occupies (or should occupy) in the minifilter driver instance stack for a volume. The higher the altitude, the farther the instance is from the base file system in the stack. Only one instance can be attached at a given altitude on a given volume.

Altitude is specified by an *altitude string*, which is a counted Unicode string consisting of one or more decimal digits from 0 through 9, and it can include a single decimal point. For example, "100.123456" and "03333" are valid altitude strings.

The string "03333" represents a higher altitude than "100.123456". (Leading and trailing zeros are ignored.) In other words, an instance whose altitude is "03333" is farther from the base file system than an instance whose altitude is "100.123456". However, this comparison is only meaningful if both instances are attached to the same volume.

**FltGetVolumeInstanceFromName** adds a rundown reference to the opaque instance pointer returned in the *RetInstance* parameter. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetVolumeInstanceFromName** must be matched by a subsequent call to **FltObjectDereference**.

## See also

[FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume)

[FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)