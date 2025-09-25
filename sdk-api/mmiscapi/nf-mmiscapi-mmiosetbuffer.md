# mmioSetBuffer function

## Description

The **mmioSetBuffer** function enables or disables buffered I/O, or changes the buffer or buffer size for a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of the file.

### `pchBuffer`

Pointer to an application-defined buffer to use for buffered I/O. If this parameter is **NULL**, **mmioSetBuffer** allocates an internal buffer for buffered I/O.

### `cchBuffer`

Size, in characters, of the application-defined buffer, or the size of the buffer for **mmioSetBuffer** to allocate.

### `fuBuffer`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. If an error occurs, the file handle remains valid. The following values are defined.

| Return code | Description |
| --- | --- |
| **MMIOERR_CANNOTWRITE** | The contents of the old buffer could not be written to disk, so the operation was aborted. |
| **MMIOERR_OUTOFMEMORY** | The new buffer could not be allocated, probably due to a lack of available memory. |

## Remarks

To enable buffering using an internal buffer, set *pchBuffer* to **NULL** and *cchBuffer* to the desired buffer size.

To supply your own buffer, set *pchBuffer* to point to the buffer, and set *cchBuffer* to the size of the buffer.

To disable buffered I/O, set *pchBuffer* to **NULL** and *cchBuffer* to zero.

If buffered I/O is already enabled using an internal buffer, you can reallocate the buffer to a different size by setting *pchBuffer* to **NULL** and *cchBuffer* to the new buffer size. The contents of the buffer can be changed after resizing.