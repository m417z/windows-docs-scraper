# MiniDumpReadDumpStream function

## Description

Reads a stream from a user-mode minidump file.

## Parameters

### `BaseOfDump` [in]

A pointer to the base of the mapped minidump file. The file should have been mapped into memory using the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) function.

### `StreamNumber` [in]

The type of data to be read from the minidump file. This member can be one of the values in the
[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type) enumeration.

### `Dir` [out]

A pointer to a [MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory)
structure.

### `StreamPointer` [out]

A pointer to the beginning of the minidump stream. The format of this stream depends on the value of
*StreamNumber*. For more information, see
[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type).

### `StreamSize` [out]

The size of the stream pointed to by *StreamPointer*, in bytes.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, the return
value is **FALSE**.

## Remarks

In this context, a data stream is a block of data written to a minidump file.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)