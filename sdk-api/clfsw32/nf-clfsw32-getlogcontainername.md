# GetLogContainerName function

## Description

Retrieves
the full path name of the specified container. This function is
used mainly to obtain the full path name of a container referenced in the
[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information) structure that is
returned in calls to [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers).

## Parameters

### `hLog` [in]

A handle to the log that is obtained from a successful call to
[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

The log handle could refer to a
log stream or a physical log.

### `cidLogicalContainer` [in]

The unique identifier that is associated with a container.

### `pwstrContainerName` [in, out]

A pointer to a user-allocated buffer to receive the full path and name of the log container, in wide characters.

### `cLenContainerName` [in]

The size of the buffer pointed to by *pwstrContainerName*, in characters.

### `pcActualLenContainerName` [in, out, optional]

A pointer to a variable to receive the actual character count of the full container path name that is retrieved.

If the function succeeds, the value of this parameter is less than or equal to
*cLenContainerName*. If the buffer is not large enough to store the whole container
path name, the function fails with **ERROR_MORE_DATA** and sets this parameter to the
size that is required for the full path name. For other failures the value is not defined.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers)