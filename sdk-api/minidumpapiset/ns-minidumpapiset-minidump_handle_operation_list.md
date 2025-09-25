# MINIDUMP_HANDLE_OPERATION_LIST structure

## Description

Contains a list of handle operations.

## Members

### `SizeOfHeader`

The size of the header data for the stream, in bytes. This is generally `sizeof(MINIDUMP_HANDLE_OPERATION_LIST)`.

### `SizeOfEntry`

The size of each entry following the header, in bytes. This is generally `sizeof(AVRF_HANDLE_OPERATION)`.

### `NumberOfEntries`

The number of entries in the stream. These are generally **AVRF_HANDLE_OPERATION** structures. The entries follow the header.

### `Reserved`

This member is reserved for future use.

## Remarks

For a definition of the **AVRF_HANDLE_OPERATION** structure, see the Avrfsdk.h header file.

## See also

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)