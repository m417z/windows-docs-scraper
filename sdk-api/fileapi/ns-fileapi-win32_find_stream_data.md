# WIN32_FIND_STREAM_DATA structure

## Description

Contains information about the stream found by the
[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw) or
[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw) function.

## Members

### `StreamSize`

A [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) value that specifies the
size of the stream, in bytes.

### `cStreamName`

The name of the stream. The string name format is
":*streamname*:$*streamtype*".

## See also

[FindFirstStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirststreamw)

[FindNextStreamW](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextstreamw)

[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)