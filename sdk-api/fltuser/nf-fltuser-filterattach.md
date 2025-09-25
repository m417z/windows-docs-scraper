# FilterAttach function

## Description

The **FilterAttach** function attaches a new minifilter instance to the given volume.

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

The *lpVolumeName* parameter is required and cannot be **NULL**.

### `lpInstanceName` [in, optional]

Pointer to a null-terminated wide-character string containing the instance name for the new instance. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the new instance receives the minifilter's default instance name as described in the Remarks section for [FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltattachvolume).

### `dwCreatedInstanceNameLength` [in, optional]

Length, in bytes, of the buffer that *lpCreatedInstanceName*  points to. This parameter is optional and can be zero.

### `lpCreatedInstanceName` [out, optional]

Pointer to a caller-allocated variable that receives the instance name for the new instance if the instance is successfully attached to the volume. This parameter is optional and can be **NULL**. If it is not **NULL**, the buffer must be large enough to hold INSTANCE_NAME_MAX_CHARS characters plus a NULL terminator.

## Return value

**FilterAttach** returns S_OK if successful. Otherwise, it returns an error value such as one of the following.

| Return code | Description |
| --- | --- |
| **ERROR_FLT_INSTANCE_ALTITUDE_COLLISION** | An instance already exists at this altitude on the volume specified. |
| **ERROR_FLT_INSTANCE_NAME_COLLISION** | An instance already exists with this name on the volume specified. |
| **ERROR_FILE_NOT_FOUND** | If *lpInstanceName* is non-**NULL**, *lpInstanceName* does not match a registered filter instance name in the registry. |

## Remarks

**FilterAttach** is the Win32 equivalent of [FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltattachvolume).

The instance name specified in *lpInstanceName* is required to be unique across the system.

To attach a minifilter instance to a volume at a given altitude, call [FilterAttachAtAltitude](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattachataltitude).

To detach a minifilter instance from a volume, call [FilterDetach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterdetach).

## See also

[FilterAttachAtAltitude](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattachataltitude)

[FilterDetach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterdetach)

[FltAttachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltattachvolume)