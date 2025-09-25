# FilterDetach function

## Description

The **FilterDetach** function detaches the given minifilter instance from the given volume.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string containing the name of the minifilter whose instance is to be detached from the stack. This parameter is required and cannot be **NULL**.

### `lpVolumeName` [in]

Pointer to a null-terminated wide-character string containing the name of the volume to which the instance is currently attached.

The *lpVolumeName* input string can be any of the following. The trailing backslash (\\) is optional.

* A drive letter, such as "D:\"
* A path to a volume mount point, such as "c:\mnt\edrive\"
* A unique volume identifier (also called a *volume GUID name*), such as "\??\Volume{7603f260-142a-11d4-ac67-806d6172696f}\"
* A nonpersistent device name (also called a *target name* or an *NT device name*), such as "\Device\HarddiskVolume1\"

This parameter is required and cannot be **NULL**.

### `lpInstanceName` [in, optional]

Pointer to a null-terminated wide-character string containing the instance name for the instance to be removed. This parameter is optional and can be **NULL**. If it is **NULL**, the highest matching instance is removed.

## Return value

**FilterDetach** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

**FilterDetach** is the Win32 equivalent of [FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltdetachvolume).

**FilterDetach** detaches a minifilter instance from a volume and tears down the instance.

To attach a minifilter instance to a volume, call [FilterAttach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattach) or [FilterAttachAtAltitude](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattachataltitude).

## See also

[FilterAttach](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattach)

[FilterAttachAtAltitude](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterattachataltitude)

[FltDetachVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltdetachvolume)