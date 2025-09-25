# MINIDUMP_USER_STREAM structure

## Description

Contains user-defined information stored in a data stream.

## Members

### `Type`

The type of data stream. For more information, see
[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type).

### `BufferSize`

The size of the user-defined data stream buffer, in bytes.

### `Buffer`

A pointer to a buffer that contains the user-defined data stream.

## Remarks

In this context, a data stream refers to a block of data within a minidump file.

## See also

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)

[MINIDUMP_USER_STREAM_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream_information)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)