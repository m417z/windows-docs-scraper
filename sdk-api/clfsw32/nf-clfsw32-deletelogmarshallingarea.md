# DeleteLogMarshallingArea function

## Description

Deletes a marshaling area that is created by a successful call to [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea).

When you delete a marshaling area it does the following:

* Flushes the log to free pending log I/O blocks
* Deallocates all log I/O blocks and invalidates all read contexts

The memory allocated by Common Log File System (CLFS) to create the marshaling context is reclaimed when all read contexts are terminated.

**Note** Clients should not delete a marshaling area if there are pending operations on the marshaling area.

## Parameters

### `pvMarshal` [in]

A pointer to the opaque marshaling context allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea)