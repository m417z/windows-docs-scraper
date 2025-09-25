# MINIDUMP_DIRECTORY structure

## Description

Contains the information needed to access a specific data stream in a minidump file.

## Members

### `StreamType`

The type of data stream. This member can be one of the values in the
[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type) enumeration.

### `Location`

A
[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor) structure that specifies the location of the data stream.

## Remarks

In this context, a data stream is a block of data within a minidump file.

## See also

[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)

[MiniDumpReadDumpStream](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpreaddumpstream)