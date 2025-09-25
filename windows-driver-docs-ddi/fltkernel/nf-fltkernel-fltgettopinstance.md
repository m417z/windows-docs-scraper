# FltGetTopInstance function

## Description

The **FltGetTopInstance** routine returns an opaque instance pointer for the minifilter driver instance that is attached at the top of the instance stack for a given volume.

## Parameters

### `Volume` [in]

Opaque pointer for the volume.

### `Instance` [out]

Pointer to a caller-allocated variable that receives an opaque instance pointer for the bottom instance for this volume. This parameter is required and cannot be **NULL**.

## Return value

**FltGetTopInstance** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_NO_MORE_ENTRIES** | No matching instance was found. This is a warning code. |

## Remarks

An instance is said to be at the *top* of the minifilter driver instance stack if its altitude is higher than that of all other instances attached to the same volume. The term "altitude" refers to the position that an instance occupies in the minifilter driver instance stack for a volume. The higher the altitude, the farther the instance is from the base file system in the stack. Only one instance can be attached at a given altitude on a given volume.

Altitude is specified by an *altitude string*, which is a counted Unicode string consisting of one or more decimal digits from 0 through 9, and it can include a single decimal point. For example, "100.123456" and "03333" are valid altitude strings.

The string "03333" represents a higher altitude than "100.123456". (Leading and trailing zeros are ignored.) In other words, an instance whose altitude is "03333" is farther from the base file system than an instance whose altitude is "100.123456". However, this comparison is only meaningful if both instances are attached to the same volume.

**FltGetTopInstance** adds a rundown reference to the opaque instance pointer returned in the *Instance* parameter. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetTopInstance** must be matched by a subsequent call to **FltObjectDereference**.

## See also

[FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume)

[FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude)

[FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes)

[FltGetBottomInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetbottominstance)

[FltGetLowerInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetlowerinstance)

[FltGetUpperInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetupperinstance)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)