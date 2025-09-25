# FilterGetDosName function

## Description

The **FilterGetDosName** function returns the MS-DOS device name that corresponds to the given volume name.

## Parameters

### `lpVolumeName` [in]

Pointer to a NULL-terminated wide-character string containing the volume name.

The *lpVolumeName* input string can be any of the following. The trailing backslash (\\) is optional.

* A drive letter, such as "D:\"
* A path to a volume mount point, such as "c:\mnt\edrive\"
* A unique volume identifier (also called a *volume GUID name*), such as "\??\Volume{7603f260-142a-11d4-ac67-806d6172696f}\"
* A nonpersistent device name (also called a *target name* or an *NT device name*), such as "\Device\HarddiskVolume1\"

This parameter is required and cannot be **NULL**.

### `lpDosName` [out]

Pointer to a caller-allocated buffer that receives the MS-DOS device name as a NULL-terminated wide-character string.

### `dwDosNameBufferSize` [in]

Size, in wide characters, of the buffer that *lpDosName*  points to.

## Return value

**FilterGetDosName** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

**FilterGetDosName** returns the volume's drive letter if it has one. If no drive letter is assigned to the volume, **FilterGetDosName** returns a path to a volume mount point (also called a *mount point name*). If no drive letters or mount points are defined for the volume, **FilterGetDosName** returns S_OK, and *lpDosName* receives **NULL**.

## See also

[DefineDosDevice](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-definedosdevicew)

[FltGetVolumeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetvolumename)

[IoQueryFileDosDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-ioqueryfiledosdevicename)

[QueryDosDevice](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-querydosdevicew)