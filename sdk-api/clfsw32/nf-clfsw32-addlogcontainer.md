# AddLogContainer function

## Description

Adds a container to the physical log that is associated with the log handle—if the calling process has write access to the .blf file and the ability to create files in the target directory of the container.

This function is different from [AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset), because it adds only one container. To add multiple containers, it is more efficient to use **AddLogContainerSet**, which allows you to add more than one container. Adding containers allows a client to increase the size of a log.

## Parameters

### `hLog` [in]

The handle to an open log.

The handle must be obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) with write access to the log. The client application must have write access to the .blf file, and the ability to create files in the target directory of a container.

### `pcbContainer` [in, optional]

The optional parameter that specifies the size of the container, in bytes.

The minimum size is 512 KB for normal logs and 1024 KB for multiplexed logs. The maximum size is approximately 4 gigabytes.

This parameter is required if the containers are being added to a newly created log. If a container is already created, this parameter can be **NULL**, or some value that is at least as large as the size of the first container.

Log container sizes are multiples of the log region size (512 KB). When you add a container to a new file, the **AddLogContainer** function rounds the size of the container up to the next 512 KB boundary, and returns that size in the value pointed to by *pcbContainer*.

Similarly, if the log already has at least one container and the value of **pcbContainer* is at least as large as the current container size, the function creates all containers with the current internal size and returns that size in **pcbContainer*.

### `pwszContainerPath` [in]

A pointer to a null-terminated string that contains a valid path for the new container on a log volume.

### `pReserved` [in, out, optional]

Reserved. Set *pReserved* to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## See also

[AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)