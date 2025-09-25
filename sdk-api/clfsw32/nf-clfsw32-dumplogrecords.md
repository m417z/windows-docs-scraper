# DumpLogRecords function

## Description

Scans a specified log; filters log records based on record type; and places the records in an output file stream that the caller opens.

## Parameters

### `pwszLogFileName` [in]

The name of the log stream.

This name is specified when you create the log by using [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile). The following example identifies the format to use:

**log:<***log name***>[::<***log stream name***>]**

<*log name*> corresponds to a valid file path in the file system.

<*log stream name*> is the unique name of a log stream in the log.

 For more information, see [Log Types](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/log-types).

### `fRecordType` [in]

The type of records to be read.

This parameter can be one or more of the following [CLFS_RECORD_TYPE Constants](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-record-type-constants).

| Value | Meaning |
| --- | --- |
| **ClfsNullRecord** | The default record type of **ClfsDataRecord** is used. |
| **ClfsDataRecord** | User data records are read. |
| **ClfsRestartRecord** | Restart records are read. |
| **ClfsClientRecord** | Both restart and data records are read. |
| **ClfsClientRecord** | Specifies a mask for all valid data or restart records. |

### `plsnStart` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) that specifies the starting log sequence number (LSN) for the log dump sequence.

If this parameter is specified, the LSN must be the address of a valid log record in the active part of the log; otherwise, the call fails with status **ERROR_INVALID_PARAMETER**.

If this parameter is not specified, the start of the dump sequence is the beginning of the active log.

### `plsnEnd` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) that specifies the LSN where the dump sequence should end.

If this LSN is past the end of the LSN range, the function returns **ERROR_HANDLE_EOF**.

Unlike *plsnStart*, this value does not have to be the LSN of a valid record in the active log, but can be any valid LSN. Only records with an LSN value less than or equal to *plsnEnd* are placed in the output stream.

If this parameter is **NULL**, the dump function uses the last LSN in the active log (at the head of the log).

### `pstrmOut` [in, optional]

A pointer to an open output stream where the log records are placed.

If this parameter is not specified, "stdout" is used as the default.

### `pfnPrintRecord` [in, optional]

A user-defined callback routine that formats user-defined buffers and prints them to the output stream *pstrmOut*.

The **DumpLogRecords** function natively outputs its internal record headers to *pstrmOut*, but depends on the user-defined callback to format the user buffers.

If this parameter is **NULL**, **DumpLogRecords** places user record data in the output stream as hexadecimal digits.

### `pfnAllocBlock` [in, optional]

A callback function that allocates memory for log blocks.

If this parameter is **NULL**, Common Log File System (CLFS) provides a default block allocation function. This parameter cannot be **NULL** if a block-freeing callback is specified by using the *pfnFreeBuffer* parameter.

The following example identifies the syntax of the block allocation callback function:

`typedef PVOID (* CLFS_BLOCK_ALLOCATION) (voidULONG cbBufferSize, PVOID pvUserContext);`

### `pfnFreeBlock` [in, optional]

A callback function that frees log blocks allocated by *pfnAllocBuffer*.

If this parameter is **NULL**, CLFS provides a default block deallocation function. This parameter cannot be **NULL** if a block allocation callback is specified by using the *pfnAllocBuffer* parameter.

The following example identifies the syntax of the block-freeing callback function:

`typedef void (* CLFS_BLOCK_DEALLOCATION) (PVOID pvBuffer, PVOID pvUserContext);`

The *buffer* parameter of "ClfsBlockDeallocProc" must point to a block that is allocated by using the callback pointed to by *pfnAllocBuffer*.

### `pvBlockAllocContext` [in, optional]

A pointer to a buffer that is passed as a user context to the block allocation and deallocation routines, if a buffer is specified.

If *pfnAllocBuffer* is **NULL**, this parameter is ignored.

### `cbBlock` [in]

The size of the buffer that your records are marshaled into, in bytes.

Records cannot be appended or read if they are longer than this value.

### `cMaxBlocks` [in]

The maximum number of blocks that can be allocated at any time for read operations.

Read contexts use at least one read block.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[CLFS_RECORD_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-record-type-constants)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)