# MINIDUMP_HANDLE_DATA_STREAM structure

## Description

Represents the header for a handle data stream.

## Members

### `SizeOfHeader`

The size of the header information for the stream, in bytes. This value is `sizeof(MINIDUMP_HANDLE_DATA_STREAM)`.

### `SizeOfDescriptor`

The size of a descriptor in the stream, in bytes. This value is `sizeof(MINIDUMP_HANDLE_DESCRIPTOR)` or `sizeof(MINIDUMP_HANDLE_DESCRIPTOR_2)`.

### `NumberOfDescriptors`

The number of descriptors in the stream.

### `Reserved`

Reserved for future use; must be zero.

## Remarks

In this context, a data stream is a set of data in a minidump file. This header structure is followed by **NumberOfDescriptors**
[MINIDUMP_HANDLE_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_descriptor) or [MINIDUMP_HANDLE_DESCRIPTOR_2](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_descriptor_2) structures.

## See also

[MINIDUMP_HANDLE_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_descriptor)

[MINIDUMP_HANDLE_DESCRIPTOR_2](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_handle_descriptor)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)