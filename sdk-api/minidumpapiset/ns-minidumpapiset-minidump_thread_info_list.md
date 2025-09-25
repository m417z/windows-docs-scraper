# MINIDUMP_THREAD_INFO_LIST structure

## Description

Contains a list of threads.

## Members

### `SizeOfHeader`

The size of the header data for the stream, in bytes. This is generally
`sizeof(MINIDUMP_THREAD_INFO_LIST)`.

### `SizeOfEntry`

The size of each entry following the header, in bytes. This is generally
`sizeof(MINIDUMP_THREAD_INFO)`.

### `NumberOfEntries`

The number of entries in the stream. These are generally
[MINIDUMP_THREAD_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info) structures. The entries
follow the header.

## See also

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)

[MINIDUMP_THREAD_INFO](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_thread_info)