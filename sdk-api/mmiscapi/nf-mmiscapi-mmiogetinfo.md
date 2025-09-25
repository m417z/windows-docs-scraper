# mmioGetInfo function

## Description

The **mmioGetInfo** function retrieves information about a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function. This information allows the application to directly access the I/O buffer, if the file is opened for buffered I/O.

## Parameters

### `hmmio`

File handle of the file.

### `pmmioinfo`

Pointer to a buffer that receives an [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure that **mmioGetInfo** fills with information about the file.

### `fuInfo`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

To directly access the I/O buffer of a file opened for buffered I/O, use the following members of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure filled by **mmioGetInfo**:

* The **pchNext** member points to the next byte in the buffer that can be read or written. When you read or write, increment **pchNext** by the number of bytes read or written.
* The **pchEndRead** member points to 1 byte past the last valid byte in the buffer that can be read.
* The **pchEndWrite** member points to 1 byte past the last location in the buffer that can be written.

After you read or write to the buffer and modify **pchNext**, do not call any multimedia file I/O functions except [mmioAdvance](https://learn.microsoft.com/previous-versions/dd757314(v=vs.85)) until you call the [mmioSetInfo](https://learn.microsoft.com/previous-versions/dd757339(v=vs.85)) function. Call **mmioSetInfo** when you are finished directly accessing the buffer.

When you reach the end of the buffer specified by the **pchEndRead** or **pchEndWrite** member, call [mmioAdvance](https://learn.microsoft.com/previous-versions/dd757314(v=vs.85)) to fill the buffer from the disk or write the buffer to the disk. The **mmioAdvance** function updates the **pchNext**, **pchEndRead**, and **pchEndWrite** members in the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure for the file.

Before calling [mmioAdvance](https://learn.microsoft.com/previous-versions/dd757314(v=vs.85)) or [mmioSetInfo](https://learn.microsoft.com/previous-versions/dd757339(v=vs.85)) to flush a buffer to disk, set the MMIO_DIRTY flag in the **dwFlags** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure for the file. Otherwise, the buffer will not be written to disk.

Do not decrement **pchNext** or modify any members in the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure other than **pchNext** and **dwFlags**. Do not set any flags in **dwFlags** except MMIO_DIRTY.