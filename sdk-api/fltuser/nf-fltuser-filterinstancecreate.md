# FilterInstanceCreate function

## Description

The **FilterInstanceCreate** function creates a handle that can be used to communicate with the given minifilter instance.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string containing the name of the minifilter that owns the instance.

### `lpVolumeName` [in]

Pointer to a null-terminated wide-character string containing the name of the volume that the instance is attached to.

The *lpVolumeName* input string can be any of the following. The trailing backslash (\\) is optional.

* A drive letter, such as "D:\"
* A path to a volume mount point, such as "c:\mnt\edrive\"
* A unique volume identifier (also called a *volume GUID name*), such as "\??\Volume{7603f260-142a-11d4-ac67-806d6172696f}\"
* A nonpersistent device name (also called a *target name* or an *NT device name*), such as "\Device\HarddiskVolume1\"

### `lpInstanceName` [in, optional]

Pointer to a null-terminated wide-character string containing the instance name for the instance. This parameter is optional and can be **NULL**. If it is **NULL**, the first instance found for this minifilter on this volume is returned.

### `hInstance` [out]

Pointer to a caller-allocated variable that receives an opaque handle for the minifilter instance if the call to **FilterInstanceCreate** succeeds; otherwise, it receives INVALID_HANDLE_VALUE.

## Return value

**FilterInstanceCreate** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

A user-mode application calls **FilterInstanceCreate** to create a handle that can be used to communicate with a kernel-mode minifilter instance. The returned instance handle can be passed as a parameter to functions such as [FilterInstanceGetInformation](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancegetinformation).

To close an instance handle returned by **FilterInstanceCreate**, call [FilterInstanceClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstanceclose).

## See also

[FilterInstanceClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstanceclose)

[FilterInstanceGetInformation](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancegetinformation)