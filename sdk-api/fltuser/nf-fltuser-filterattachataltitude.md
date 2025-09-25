# FilterAttachAtAltitude function

## Description

The **FilterAttachAtAltitude** function is a debugging support function that attaches a new minifilter instance to a volume at a specified altitude, overriding any settings in the minifilter's setup information (INF) file.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string containing the name of the minifilter for which an instance is to be created. This parameter is required and cannot be **NULL**.

### `lpVolumeName` [in]

Pointer to a null-terminated wide-character string containing the name of the volume to which the newly created instance is to be attached.

The *lpVolumeName* input string can be any of the following. The trailing backslash (\\) is optional.

* A drive letter, such as "D:\"
* A path to a volume mount point, such as "c:\mnt\edrive\"
* A unique volume identifier (also called a *volume GUID name*), such as "\??\Volume{7603f260-142a-11d4-ac67-806d6172696f}\"
* A nonpersistent device name (also called a *target name* or an *NT device name*), such as "\Device\HarddiskVolume1\"

This parameter is required and cannot be **NULL**.

### `lpAltitude` [in]

Pointer to a null-terminated wide-character string that contains a numeric value specifying the target position that the minifilter instance should occupy in the stack for the volume. The higher the number, the higher the relative position in the stack. An altitude string consists of one or more digits in the range from 0 through 9, and it can include a single decimal point. The decimal point is optional. For example, "100.123456" is a valid altitude string. This parameter is required and cannot be **NULL**.

### `lpInstanceName` [in, optional]

Pointer to a null-terminated wide-character string containing the instance name for the new instance. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the new instance receives the minifilter's default instance name as described in the Remarks section for [FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltattachvolume).

### `dwCreatedInstanceNameLength` [in, optional]

Length, in bytes, of the buffer that *lpCreatedInstanceName*  points to. This parameter is optional and can be zero.

### `lpCreatedInstanceName` [out, optional]

Pointer to a caller-allocated variable that receives the instance name for the new instance if the instance is successfully attached to the volume. This parameter is optional and can be **NULL**. If it is not **NULL**, the buffer must be large enough to hold INSTANCE_NAME_MAX_CHARS characters plus a NULL terminator.

## Return value

**FilterAttachAtAltitude** returns S_OK if successful. Otherwise, it returns an error value such as one of the following.

| Return code | Description |
| --- | --- |
| **ERROR_FLT_INSTANCE_ALTITUDE_COLLISION** | An instance already exists at this altitude on the volume specified. |
| **ERROR_FLT_INSTANCE_NAME_COLLISION** | An instance already exists with this name on the volume specified. |

## Remarks

An application should only use **FilterAttachAtAltitude** for debugging. It should not call this function in a retail version of the application.

**FilterAttachAtAltitude** is the Win32 equivalent of [FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltattachvolumeataltitude).

The term "altitude" refers to the position that an instance occupies (or should occupy) in the minifilter instance stack for a volume. The higher the altitude, the farther the instance is from the base file system in the stack. Only one instance can be attached at a given altitude on a given volume.

Altitude is specified by an *altitude string*, which is a wide-character array containing one or more decimal digits in the range from 0 through 9, and it can include a single decimal point. The decimal point is optional. For example, "100.123456" and "03333" are valid altitude strings.

The string "03333" represents a higher altitude than "100.123456". (Leading and trailing zeros are ignored.) In other words, an instance whose altitude is "03333" is farther from the base file system than an instance whose altitude is "100.123456". However, this comparison is only meaningful if both instances are attached to the same volume.

The instance name returned in *lpCreatedInstanceName* is unique across the system.

To detach a minifilter instance from a volume, call [FilterDetach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterdetach).

## See also

[FilterAttach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattach)

[FilterDetach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterdetach)

[FltAttachVolumeAtAltitude](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltattachvolumeataltitude)