# MINIDUMP_FUNCTION_TABLE_STREAM structure

## Description

Represents the header for the function table stream.

## Members

### `SizeOfHeader`

The size of header information for the stream, in bytes. This value is `sizeof(MINIDUMP_FUNCTION_TABLE_STREAM)`.

### `SizeOfDescriptor`

The size of a descriptor in the stream, in bytes. This value is `sizeof(MINIDUMP_FUNCTION_TABLE_DESCRIPTOR)`.

### `SizeOfNativeDescriptor`

The size of a raw system descriptor in the stream, in bytes. This value depends on the particular platform and system version on which the minidump was generated.

### `SizeOfFunctionEntry`

The size of a raw system function table entry, in bytes. This value depends on the particular platform and system version on which the minidump was generated.

### `NumberOfDescriptors`

The number of descriptors in the stream.

### `SizeOfAlignPad`

The size of alignment padding that follows the header, in bytes.

## Remarks

In this context, a data stream is a set of data in a minidump file. This header structure is followed by **NumberOfDescriptors** function tables. For each function table there is a
[MINIDUMP_FUNCTION_TABLE_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_function_table_descriptor) structure, then the raw system descriptor for the table, then the raw system function entry data. If necessary, alignment padding is placed between tables to properly align the initial structures.

## See also

[MINIDUMP_FUNCTION_TABLE_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_function_table_descriptor)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)