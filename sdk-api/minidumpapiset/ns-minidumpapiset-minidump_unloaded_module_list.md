# MINIDUMP_UNLOADED_MODULE_LIST structure

## Description

Contains a list of unloaded modules.

## Members

### `SizeOfHeader`

The size of the header data for the stream, in bytes. This is generally `sizeof(MINIDUMP_UNLOADED_MODULE_LIST)`.

### `SizeOfEntry`

The size of each entry following the header, in bytes. This is generally `sizeof(MINIDUMP_UNLOADED_MODULE)`.

### `NumberOfEntries`

The number of entries in the stream. These are generally [MINIDUMP_UNLOADED_MODULE](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_unloaded_module) structures. The entries follow the header.

## See also

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)

[MINIDUMP_UNLOADED_MODULE](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_unloaded_module)