# FltCompareInstanceAltitudes function

## Description

**FltCompareInstanceAltitudes** compares the altitudes of two minifilter driver instances.

## Parameters

### `Instance1` [in]

Pointer to the first instance.

### `Instance2` [in]

Pointer to the second instance.

## Return value

**FltCompareInstanceAltitudes** returns a signed value that gives the results of the comparison as follows:

| Return code | Description |
| --- | --- |
| **Zero** | *Instance1* is attached at the same altitude as *Instance2*. This can only occur if *Instance1* and *Instance2* are attached to different volumes or if *Instance1* and *Instance2* are pointers to the same instance. |
| **Less than zero** | *Instance1* is attached at a lower altitude than *Instance2*. |
| **Greater than zero** | *Instance1* is attached at a higher altitude than *Instance2*. |

## Remarks

The minifilter driver instances that *Instance1* and *Instance2* point to can be instances of the same minifilter driver or different minifilter drivers. However, they must be attached to the same volume if the result returned by **FltCompareInstanceAltitudes** is to be meaningful.

The term "altitude" refers to the position that an instance occupies (or should occupy) in the minifilter driver instance stack for a volume. The higher the altitude, the farther the instance is from the base file system in the stack. Only one instance can be attached at a given altitude on a given volume.

Altitude is specified by an *altitude string*, which is a counted Unicode string that consists of one or more decimal digits from 0 through 9; the string can include a single decimal point. For example, "100.123456" and "03333" are valid altitude strings.

The string "03333" represents a higher altitude than "100.123456" (Leading and trailing zeros are ignored.) In other words, an instance whose altitude is "03333" is farther from the base file system than an instance whose altitude is "100.123456". However, this comparison is only meaningful if both instances are attached to the same volume.

To attach a minifilter driver instance to a volume, call [FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume) or [FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude).

To detach a minifilter driver instance from a volume, call [FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume).

## See also

[FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolume)

[FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltattachvolumeataltitude)

[FltCompareInstanceAltitudes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompareinstancealtitudes)

[FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdetachvolume)