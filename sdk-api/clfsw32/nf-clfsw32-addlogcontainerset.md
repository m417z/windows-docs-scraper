# AddLogContainerSet function

## Description

Adds multiple log containers to the physical log that is associated with the log handle—if the calling process has access to the log handle. Adding containers allows a client to increase the size of a log.

## Parameters

### `hLog` [in]

The handle to an open log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) with permissions to add a log container.

The file can be dedicated or multiplexed.

### `cContainer` [in]

The number of containers in the *rgwszContainerPath* array.

This value must be nonzero. A log must have at least two containers before any I/O can be performed on it.

### `pcbContainer` [in, optional]

The size of the container, in bytes.

The minimum size is 512 KB for normal logs and 1024 KB for multiplexed logs. The maximum size is approximately 4 gigabytes (GB).

This parameter is required if the containers are being added to a newly created log. If a container is already created, this parameter can be **NULL**, or some value that is at least as large as the size of the first container.

Log container sizes are multiples of the log region size (512 KB). When you add a container to a new file, the [AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer) function rounds the size of the container up to the next 512 KB boundary, and returns that size in the value pointed to by *pcbContainer*.

Similarly, if the log already has at least one container and the value of **pcbContainer* is at least as large as the current container size, the function creates all containers with the current internal size and returns that size in **pcbContainer*.

### `rgwszContainerPath` [in]

An array of *cContainer* path names for containers.

Each element in the array is a wide-character string that contains a valid path for the new container in the log volume.

### `pReserved` [in, out, optional]

Reserved. Set *Reserved* to **NULL**.

## Return value

If the function succeeds, the return value is nonzero, which indicates that all containers are added successfully to the log.

If the function fails, the return value is zero, which indicates that none of the containers are added. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

 The **AddLogContainerSet** function is not atomic. If the operation
is interrupted, for example, by an invalid path name, the call to
**AddLogContainerSet** returns a failure, but some containers may
have been created. Your application must recover from this error, for example, by determining which containers were added.

Because **AddLogContainerSet** adds more than one container, it is more
efficient than making repeated calls to [AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer), which only adds one container.

Containers are created and opened in a noncompressed mode, and are initialized with 0 (zeros) when they are created.

## See also

[AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)