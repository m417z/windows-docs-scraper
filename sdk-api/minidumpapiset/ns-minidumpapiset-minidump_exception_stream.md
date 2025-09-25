# MINIDUMP_EXCEPTION_STREAM structure

## Description

Represents an exception information stream.

## Members

### `ThreadId`

The identifier of the thread that caused the exception.

### `__alignment`

A variable for alignment.

### `ExceptionRecord`

A
[MINIDUMP_EXCEPTION](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_exception) structure.

### `ThreadContext`

A
[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor) structure.

## Remarks

In this context, a data stream is a set of data in a minidump file.

## See also

[MINIDUMP_EXCEPTION](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_exception)

[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)