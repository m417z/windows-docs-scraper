# ClfsRemoveLogContainerSet function

## Description

The **ClfsRemoveLogContainerSet** routine atomically removes a set of containers from a CLFS log.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log from which the containers will be removed. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `cContainers` [in]

The number of containers in the set. This is the number of elements in the *rgwszContainerPath* array.

### `rgwszContainerPath` [in]

A pointer to an array of [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structures, each of which supplies the path name for one of the containers to be removed. The number of elements in the array is given by *cContainers*. A given path can be absolute or relative to the location of the base log file for the CLFS log represented by *plfoLog*. Paths that are relative to the base log file must begin with CLFS_CONTAINER_RELATIVE_PREFIX, which is the string literal (L"%BLF%\\"). The directories "." and ".." are not allowed in a relative path.

### `fForce` [in]

A Boolean value that specifies whether the container removal is forced (**TRUE**) or lazy (**FALSE**).

## Return value

**ClfsRemoveLogContainerSet** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

Forced container removal (*fForce* = **TRUE**) succeeds only if the containers to be removed are not part of the active log.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAddLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainerset)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsRemoveLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsremovelogcontainer)

[LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)