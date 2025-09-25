# RemoveLogContainer function

## Description

Removes one container from a log that is associated with a dedicated or multiplexed log handle.

A client must have administrative privileges on the log handle to remove a container. To remove multiple containers, use the [RemoveLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-removelogcontainerset) function.

## Parameters

### `hLog` [in]

A handle to the log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

### `pwszContainerPath` [in]

A pointer to a wide character string that contains a path for a log container that is created by either [AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer) or [AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset).

### `fForce` [in]

The deletion flag that determines when and how a container is deleted.

If *fForce* is **TRUE**, and the container is part of the active log region, the container is not deleted and an error **ERROR_LOG_CANT_DELETE** is returned.

If **FALSE**, the container is deleted when the container is no longer a part of the active log region.

### `pReserved` [in, out, optional]

This parameter is reserved and should be set to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

 The following list identifies the possible error codes:

## Remarks

 By default, container deletion is lazy, which means that a container is deleted only if it is not part of an active log. If the container is part of the active log, it is marked for deletion. However, deletion does not occur until the end of the log exceeds the last sector of the container, or the container has a logical identifier that is greater than the logical identifier of the head of the active log. The log size reflects the container deletion only when the container is deleted physically.

A log client can request a forced deletion on a container by setting the deletion flag to **TRUE**. This has the same effect as deleting a container that is not part of the active log. However, if the container is part of the active log, the call fails without marking the container for deletion.

## See also

[AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer)

[AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[RemoveLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-removelogcontainerset)