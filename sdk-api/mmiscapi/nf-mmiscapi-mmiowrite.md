# mmioWrite function

## Description

The **mmioWrite** function writes a specified number of bytes to a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of the file.

### `pch`

Pointer to the buffer to be written to the file.

### `cch`

Number of bytes to write to the file.

## Return value

Returns the number of bytes actually written. If there is an error writing to the file, the return value is -1.

## Remarks

The current file position is incremented by the number of bytes written.