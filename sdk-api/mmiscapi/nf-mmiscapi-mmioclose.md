# mmioClose function

## Description

The **mmioClose** function closes a file that was opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of the file to close.

### `fuClose`

Flags for the close operation. The following value is defined.

| Value | Meaning |
| --- | --- |
| MMIO_FHOPEN | If the file was opened by passing a file handle whose type is not **HMMIO**, using this flag tells the **mmioClose** function to close the multimedia file handle, but not the standard file handle. |

## Return value

Returns zero if successful or an error otherwise. The error value can originate from the [mmioFlush](https://learn.microsoft.com/previous-versions/dd757319(v=vs.85)) function or from the I/O procedure. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMIOERR_CANNOTWRITE** | The contents of the buffer could not be written to disk. |