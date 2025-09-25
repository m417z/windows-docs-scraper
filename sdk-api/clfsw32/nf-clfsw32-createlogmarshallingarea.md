# CreateLogMarshallingArea function

## Description

Creates a marshaling area for a log, and when successful it returns a marshaling context. Before creating a marshaling area, the log must have at least one container.

The marshaling context is used to append records to or read records from a log. Because records are always stored in log blocks, they must pass through the marshaling context.

Log records are written by calling [ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog).

## Parameters

### `hLog` [in]

A handle to the log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

The log handle can refer to a dedicated or multiplexed log.

### `pfnAllocBuffer` [in, optional]

The callback function that allocates memory for log blocks.

If this parameter is **NULL**, the Common Log File System (CLFS) provides a default block allocation function. This parameter cannot be **NULL** if a block-freeing callback is specified by using the *pfnFreeBuffer* parameter.

The following example identifies the syntax of the block allocation callback function:

`typedef PVOID (* CLFS_BLOCK_ALLOCATION) (ULONG cbBufferSize, PVOID pvUserContext);`

### `pfnFreeBuffer` [in, optional]

The callback function that frees log blocks allocated by *pfnAllocBuffer*.

If this parameter is **NULL**, CLFS provides a default block deallocation function. This parameter cannot be **NULL** if a block allocation callback is specified by using the *pfnAllocBuffer* parameter.

The following example identifies the syntax of the block-freeing callback function:

`typedef void (* CLFS_BLOCK_DEALLOCATION) (PVOID pvBuffer, PVOID pvUserContext);`

The *buffer* parameter of "ClfsBlockDeallocProc" must point to a block that is allocated by using the callback pointed to by *pfnAllocBuffer*.

### `pvBlockAllocContext` [in, optional]

A pointer to a buffer that is passed back as a user context to the block allocation and deallocation routines, if a buffer is specified.

If *pfnAllocBuffer* is **NULL**, this parameter is ignored.

### `cbMarshallingBuffer` [in]

The size, in bytes, of the individual log I/O blocks that will be used by the new marshaling area. This must be a multiple of the sector size on the stable storage medium. The sector size is the value returned in the *lpBytesPerSector* parameter of the [GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function.

Records cannot be appended or read if they are longer than this value.

### `cMaxWriteBuffers` [in]

The maximum number of blocks that can be allocated at any time for write operations.

This value can affect the frequency of data flushes. If you do not need to specify a limit to control the frequency of the data flush cycle, specify INFINITE.

### `cMaxReadBuffers` [in]

The maximum number of blocks that can be allocated at any time for read operations.

Read contexts use at least one read block.

### `ppvMarshal` [out]

A pointer to the marshaling context that CLFS allocates when **CreateLogMarshallingArea** completes successfully.

This context must be used with all read, append, write, and flush operations to log marshaling areas. All operations that access marshaling areas by using a marshaling context are thread-safe. This parameter is **NULL** if the operation is not successful.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)

[DeleteLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-deletelogmarshallingarea)