# STREAM_SEEK enumeration

## Description

The
**STREAM_SEEK** enumeration values specify the origin from which to calculate the new seek-pointer location. They are used for the *dworigin* parameter in the
[IStream::Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek) method. The new seek position is calculated using this value and the *dlibMove* parameter.

## Constants

### `STREAM_SEEK_SET:0`

The new seek pointer is an offset relative to the beginning of the stream. In this case, the *dlibMove* parameter is the new seek position relative to the beginning of the stream.

### `STREAM_SEEK_CUR:1`

The new seek pointer is an offset relative to the current seek pointer location. In this case, the *dlibMove* parameter is the signed displacement from the current seek position.

### `STREAM_SEEK_END:2`

The new seek pointer is an offset relative to the end of the stream. In this case, the *dlibMove* parameter is the new seek position relative to the end of the stream.

## See also

[IStream::Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek)