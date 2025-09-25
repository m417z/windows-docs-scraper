# ClfsAddLogContainer function

## Description

The **ClfsAddLogContainer** routine adds a container to a CLFS log.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the log to which the container will be added. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `pcbContainer` [in]

A pointer to a ULONGLONG-typed variable. The role of this parameter depends on whether the log currently has at least one container.

* If the log currently has no containers, the caller supplies a positive integer that is the requested size, in bytes, of the new container. CLFS creates a container that is the requested size rounded up to a multiple of 512KB (for a dedicated log) or 1MB (for a multiplexed log).
* If the log currently has at least one container and this parameter is the **NULL** pointer, CLFS creates a new container that is the same size as the existing containers. (All containers in a log must be the same size.)
* If the log currently has at least one container and this parameter is a valid pointer, the caller supplies a positive integer that is the requested size, in bytes, of the new container. The requested size is rounded up to a multiple of 512KB (for a dedicated log) or 1MB (for a multiplexed log). If the rounded-up size is at least as large as the existing container size, CLFS creates a new container that is the same size as the existing containers. On successful return, this parameter receives the existing container size. If the rounded-up size is less than the existing container size, **ClfsAddLogContainer** fails.

### `puszContainerPath` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the path name for the new container. The path can be absolute or relative to the location of the base log file. Paths that are relative to the base log file must begin with CLFS_CONTAINER_RELATIVE_PREFIX, which is the string literal (L"%BLF%\\").

## Return value

**ClfsAddLogContainer** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

A container is a contiguous extent on stable storage. For example, a container could be a contiguous file on disk. A log is a set of containers along with a base log file. For more information about containers, see [CLFS Stable Storage](https://learn.microsoft.com/windows-hardware/drivers/kernel/clfs-stable-storage).

A container specified by a path that is relative to the base log file must be in the same directory as the base log file or a subdirectory of the base log file. The directories "." and ".." are not allowed in a relative path.

A log can have some containers with absolute paths and other containers with relative paths.

Containers are created in a non-compressed mode and are initialized with zeros.

A log must have at least two containers before any I/O can be performed on it.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAddLogContainerSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainerset)

[ClfsRemoveLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsremovelogcontainer)