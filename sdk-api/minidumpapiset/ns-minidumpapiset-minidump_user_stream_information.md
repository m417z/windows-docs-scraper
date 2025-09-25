# MINIDUMP_USER_STREAM_INFORMATION structure

## Description

Contains a list of user data streams used by the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

## Members

### `UserStreamCount`

The number of user streams.

### `UserStreamArray`

An array of
[MINIDUMP_USER_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream) structures.

## Remarks

In this context, a data stream refers to a block of data within a minidump file.

## See also

[MINIDUMP_USER_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)