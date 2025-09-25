# mmioAdvance function

## Description

The **mmioAdvance** function advances the I/O buffer of a file set up for direct I/O buffer access with the [mmioGetInfo](https://learn.microsoft.com/previous-versions/dd757321(v=vs.85)) function.

## Parameters

### `hmmio`

File handle of a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

### `pmmioinfo`

Pointer to the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure obtained by using the [mmioGetInfo](https://learn.microsoft.com/previous-versions/dd757321(v=vs.85)) function. This structure is used to set the current file information, and then it is updated after the buffer is advanced. This parameter is optional.

### `fuAdvance`

Flags for the operation. It can be one of the following.

| Value | Meaning |
| --- | --- |
| MMIO_READ | Buffer is filled from the file. |
| MMIO_WRITE | Buffer is written to the file. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMIOERR_CANNOTEXPAND** | The specified memory file cannot be expanded, probably because the **adwInfo** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure was set to zero in the initial call to the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function. |
| **MMIOERR_CANNOTREAD** | An error occurred while refilling the buffer. |
| **MMIOERR_CANNOTWRITE** | The contents of the buffer could not be written to disk. |
| **MMIOERR_OUTOFMEMORY** | There was not enough memory to expand a memory file for further writing. |
| **MMIOERR_UNBUFFERED** | The specified file is not opened for buffered I/O. |

## Remarks

If the file is opened for reading, the I/O buffer is filled from the disk. If the file is opened for writing and the MMIO_DIRTY flag is set in the **dwFlags** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure, the buffer is written to disk. The **pchNext,****pchEndRead**, and **pchEndWrite** members of the **MMIOINFO** structure are updated to reflect the new state of the I/O buffer.

If the specified file is opened for writing or for both reading and writing, the I/O buffer is flushed to disk before the next buffer is read. If the I/O buffer cannot be written to disk because the disk is full, **mmioAdvance** returns MMIOERR_CANNOTWRITE.

If the specified file is open only for writing, the MMIO_WRITE flag must be specified.

If you have written to the I/O buffer, you must set the MMIO_DIRTY flag in the **dwFlags** member of the **MMIOINFO** structure before calling **mmioAdvance**. Otherwise, the buffer will not be written to disk.

If the end of file is reached, **mmioAdvance** still returns successfully even though no more data can be read. To check for the end of the file, check if the **pchNext** and **pchEndRead** members of the **MMIOINFO** structure are equal after calling **mmioAdvance**.