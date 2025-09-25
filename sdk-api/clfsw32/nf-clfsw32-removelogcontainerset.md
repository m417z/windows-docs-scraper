# RemoveLogContainerSet function

## Description

Removes multiple containers from a log that is associated with a dedicated or multiplexed log handle.

A client must have administrative privileges on the log handle to remove a container. The [RemoveLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-removelogcontainer) function is a special case of this **RemoveLogContainerSet** function, because it removes only one container. To remove multiple containers, use the **RemoveLogContainerSet**.

## Parameters

### `hLog` [in]

A handle to the log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

The log handle must have administrative permission to add a log container, and can refer to either a dedicated or multiplexed log.

### `cContainer` [in]

The number of container path names in an array that is pointed to by *rgwszContainerPath*.

This value must be nonzero.

### `rgwszContainerPath` [in]

An array of pointers to container path names that contain *cContainers* pointers.

Each path name is a wide character string that identifies a container created by either [AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer) or [AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset).

### `fForce` [in]

The deletion flag that determines when and how a container is deleted.

If *fForce* is **TRUE**, and the container is part of the active log region, the container is not deleted and an error **ERROR_LOG_CANT_DELETE** is returned.

If **FALSE**, the container is deleted when the container is no longer a part of the active log region.

### `pReserved` [in, out, optional]

Reserved. Set *pReserved* to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

By default, container deletion is lazy, which means that a container is deleted only if it is not part of the active log. If the container is part of the active log it is marked for deletion. This deletion is deferred until the tail of the log exceeds the last sector of the container, or the container has a logical identifier that is greater than the logical identifier of the head of the active log. The log size reflects the container deletion only when the container is deleted physically.

A log client can request a forced deletion on a container by setting the deletion flag to **TRUE**. This has the same effect as deleting a container that is not part of the active log. However, if a container is part of the active log, the call fails without marking the container for deletion.

## See also

[AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer)

[AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[RemoveLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-removelogcontainer)