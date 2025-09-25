# mmioRead function

## Description

The **mmioRead** function reads a specified number of bytes from a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of the file to be read.

### `pch`

Pointer to a buffer to contain the data read from the file.

### `cch`

Number of bytes to read from the file.

## Return value

Returns the number of bytes actually read. If the end of the file has been reached and no more bytes can be read, the return value is 0. If there is an error reading from the file, the return value is –1.