# mmioSeek function

## Description

The **mmioSeek** function changes the current file position in a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of the file to seek in.

### `lOffset`

Offset to change the file position.

### `iOrigin`

Flags indicating how the offset specified by *lOffset* is interpreted. The following values are defined:

| Name | Description |
| --- | --- |
| **SEEK_CUR** | Seeks to *lOffset* bytes from the current file position. |
| **SEEK_END** | Seeks to *lOffset* bytes from the end of the file. |
| **SEEK_SET** | Seeks to *lOffset* bytes from the beginning of the file. |

## Return value

Returns the new file position, in bytes, relative to the beginning of the file. If there is an error, the return value is –1.

## Remarks

Seeking to an invalid location in the file, such as past the end of the file, might not cause **mmioSeek** to return an error, but it might cause subsequent I/O operations on the file to fail.

To locate the end of a file, call **mmioSeek** with *lOffset* set to zero and *iOrigin* set to SEEK_END.