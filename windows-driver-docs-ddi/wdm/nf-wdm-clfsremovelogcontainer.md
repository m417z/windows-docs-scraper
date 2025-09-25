# ClfsRemoveLogContainer function

## Description

The **ClfsRemoveLogContainer** routine removes a container from a CLFS log.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS log from which the container will be removed. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `puszContainerPath` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the path name for the container to be removed. The path name was created in a previous call to [ClfsAddLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainer) or [ClfsAddLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainerset). The path can be absolute or relative to the location of the base log file for the CLFS log that is represented by *plfoLog*. Paths that are relative to the base log file must begin with CLFS_CONTAINER_RELATIVE_PREFIX, which is the string literal (L"%BLF%\\"). The directories "." and ".." are not allowed in a relative path.

### `fForce` [in]

A Boolean value that specifies whether the container removal is forced (**TRUE**) or lazy (**FALSE**).

## Return value

**ClfsRemoveLogContainer** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

Forced container removal (*fForce* = **TRUE**) succeeds only if the container to be removed is not part of the active log.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAddLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainer)

[ClfsAddLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainerset)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsRemoveLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsremovelogcontainerset)

[LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)