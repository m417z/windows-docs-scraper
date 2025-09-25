# MINIDUMP_FUNCTION_TABLE_DESCRIPTOR structure

## Description

Represents a function table stream.

## Members

### `MinimumAddress`

The minimum address of functions described by the table.

### `MaximumAddress`

The maximum address of functions described by the table.

### `BaseAddress`

The base address to use when computing full virtual addresses from relative virtual addresses in function entries.

### `EntryCount`

The number of entries in the function table.

### `SizeOfAlignPad`

The size of alignment padding that follows the function entry data, in bytes. The function entry data in the stream is guaranteed to be aligned appropriately for access to the data members. If a minidump is directly mapped in memory, it is always possible to directly reference structure members in the stream.

## Remarks

The first descriptor in the function table stream follows the header,
[MINIDUMP_FUNCTION_TABLE_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_function_table_stream). The generic descriptor is followed by a native system descriptor, then by **EntryCount** native system function entry structures.

## See also

[MINIDUMP_FUNCTION_TABLE_STREAM](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_function_table_stream)